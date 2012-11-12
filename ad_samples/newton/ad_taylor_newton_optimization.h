#include "../hessian/ad_taylor_gradient_hessian.h"

template<typename realT, int NVARS>
void sle_solver_lup(const realT (&a_matrix)[NVARS][NVARS], const realT (&b_vector)[NVARS], realT (&solution)[NVARS], realT epsilon)
{
	//Fill in permutation vecor and copy sources
	realT decomposed_matrix[NVARS][NVARS];
	int permutation_history[NVARS];
	for(int i = 0; i < NVARS; i++)
	{
		permutation_history[i] = i;
		solution[i] = -b_vector[i];
		decomposed_matrix[i][i] = a_matrix[i][i];
		for(int j = i + 1; j < NVARS; j++)
		{
			decomposed_matrix[i][j] = a_matrix[i][j];
			decomposed_matrix[j][i] = a_matrix[j][i];
		}
	}
    //LUP decomposition main loop
	for(int i = 0; i < NVARS; i++) 
	{
		//Look up for pivot element
        realT pivot_value = 0;
        int pivot = -1;
        for(int row = i; row < NVARS; row++) 
		{
            if(fabs(decomposed_matrix[row][i]) > pivot_value) 
			{
                pivot_value = fabs(decomposed_matrix[row][i]);
                pivot = row;
            }
        }
        //Check if matrix is not degenerated: det(decomposed_matrix) != 0
		if(pivot_value < epsilon) 
		{  
			printf("ERROR: Degenerated matrix cannot be decomposed by any LU-like method\n"); 
			//Another degenarted matrix friendly method should be applied (maybe SVD)
            return;
        }
		//Swap rows: pivot -> current(i)
		if(pivot != i)
		{
			int swap;
			swap = permutation_history[pivot];
			permutation_history[pivot] = permutation_history[i];
			permutation_history[i] = swap;
			for(int j = 0; j < NVARS; j++)
			{
				realT swap;
				swap = decomposed_matrix[pivot][j];
				decomposed_matrix[pivot][j] = decomposed_matrix[i][j];
				decomposed_matrix[i][j] = swap;
			}
		}
		//LU-decomposition for current row
		for(int j = i + 1; j < NVARS; j++) 
		{
            decomposed_matrix[j][i] /= decomposed_matrix[i][i];
            for(int k = i + 1; k < NVARS; k++ )
			{
                decomposed_matrix[j][k] -= decomposed_matrix[j][i] * decomposed_matrix[i][k];
			}
        }
    }
	//Upper matrix solver run
	for(int i = 0; i < NVARS; i++)
	{
		int row = NVARS - i - 1;
		for(int j = 0; j < i; j++)
		{
			int col = NVARS - j - 1;
			solution[permutation_history[row]] -= decomposed_matrix[row][col] * solution[permutation_history[col]];
		}
		solution[permutation_history[row]] /= decomposed_matrix[row][row];
	}
	//Lower matrix solver run
	for(int i = 0; i < NVARS; i++)
	{
		for(int j = 0; j < i; j++)
		{
			solution[permutation_history[i]] -= decomposed_matrix[i][j] * solution[permutation_history[j]];
		}
	}
}

template<typename realT, int NVARS, int NITERS, class FUNC>
void newton_optimizator(const realT (&aargs)[NVARS], const realT EPSILON)
{
	realT nargs[NVARS];
	for (int i=0; i<NVARS; i++) nargs[i] = aargs[i];

	int iteration = 0;
	ad_taylor_grad_and_hessian_t<realT, NVARS, FUNC> ad_function;
	double condition;
	for(int iteration = 0; iteration < NITERS; iteration++)
	{
		ad_function.compute(nargs);
		double shifts[NVARS]; 
		sle_solver_lup<double, NVARS>(ad_function.hessian, ad_function.gradient, shifts, EPSILON);
		condition = 0;
		for(int i = 0; i < NVARS; i++)
		{
			nargs[i] += shifts[i];
			condition += shifts[i] * shifts[i];
		}
		if(condition > EPSILON * EPSILON) break;  
	}
}