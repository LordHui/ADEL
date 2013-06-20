#ifndef ADVARIABLE_H
#define ADVARIABLE_H

#include <string>
#include <vector>
#include "ADHelper.h"

template<unsigned Level, unsigned Nvars>
struct ADVariable : StaticInterface<ADVariable<Level, Nvars>> {
    static const unsigned CurrentSize = ADVariable < Level - 1, Nvars >::CurrentSize* Nvars;
    static const unsigned TotalSize = ADVariable < Level - 1, Nvars >::TotalSize + CurrentSize;
    real Value;
    real Data[TotalSize];
    mutable unsigned ID;
    mutable bool Base;

    template<typename R>
    ADVariable(const StaticInterface<R>& expression): ID(-1), Base(false) {
        std::vector<const ADVariable<Level, Nvars>*> temporaries;
        expression.Self().GetTemporaries(temporaries);
        unsigned tmpCount = static_cast<unsigned>(temporaries.size());
        Value = expression.Self().Value;
        if (tmpCount == 0) {
            memset(Data, 0, TotalSize * sizeof(real));
            expression.Self().Gradient<Level>(Data, 0, Nvars + tmpCount, 1.0);
        } else {
            unsigned tmpSize = ADHelper<Level, Nvars>::GetDataSize(Level, Nvars + tmpCount);
            real* tmpData = static_cast<real*>(malloc(tmpSize * sizeof(real)));
            memset(tmpData, 0, tmpSize * sizeof(real));
            expression.Self().Gradient<Level>(tmpData, 0, Nvars + tmpCount, 1.0);
            ADHelper<Level, Nvars>::Crop<Level>(tmpData, Data, 0, 0, tmpCount);
            ADHelper<Level, Nvars>::Inject<Level>(temporaries, tmpData, Data);
            free(tmpData);
            for (unsigned i = 0; i < tmpCount; i++)
                temporaries[i]->Base = false;
        }
    }

    ADVariable(): ID(-1), Base(false), Value(0.0) {
        memset(Data, 0, TotalSize * sizeof(real));
    }

    ADVariable(const real& value): ID(-1), Base(false), Value(value) {
        memset(Data, 0, TotalSize * sizeof(real));
    }

    ADVariable& operator =(const real& value) {
        Value = value;
        memset(Data, 0, TotalSize * sizeof(real));
        return *this;
    }

    ADVariable(const ADVariable& other): ID(-1), Base(false), Value(other.Value) {
        Value = other.Value;
        if (other.Base) {
            memset(Data, 0, TotalSize * sizeof(real));
            Data[other.ID] = 1.0;
        } else {
            memcpy(Data, other.Data, TotalSize * sizeof(real));
        }
    }

    ADVariable& operator=(const ADVariable& other) {
        ID = -1;
        Base = false;
        Value = other.Value;
        if (other.Base) {
            memset(Data, 0, TotalSize * sizeof(real));
            Data[other.ID] = 1.0;
        } else {
            memcpy(Data, other.Data, TotalSize * sizeof(real));
        }
        return *this;
    }

    template<unsigned NewBase>
    ADVariable<Level, NewBase> ChangeBase(const ADVariable<Level, NewBase> (&oldBase)[Nvars]) {
        ADVariable<Level, NewBase> result;
        result.ID = -1;
        result.Base = false;
        result.Value = Value;
        unsigned resDataSize = ADVariable<Level, NewBase>::TotalSize;
        memset(result.Data, 0, resDataSize * sizeof(real));
        ADHelper<Level, Nvars>::Morpher<Level, NewBase>::Morph(oldBase, Data, result.Data);
        return result;
    }

    template<unsigned Level, unsigned Nvars>
    void GetTemporaries(std::vector<const ADVariable<Level, Nvars>*>& temporaries)const {
        if (!Base) {
            ID = Nvars + static_cast<unsigned>(temporaries.size());
            temporaries.push_back(this);
            Base = true;
        }
    }

    template<unsigned GradLevel, typename T>
    void Gradient(real gradData[], unsigned index, const unsigned baseCount, const T& gradient)const {
        gradData[ADHelper<Level, Nvars>::GetDataSize(Level - GradLevel, baseCount) + index + ID] += gradient.Self().Value;
        gradient.Self().Gradient < GradLevel - 1 > (gradData, (index + ID) * baseCount, baseCount, 1.0);
    }

    template<unsigned GradLevel>
    void Gradient(real gradData[], unsigned index, const unsigned baseCount, const real& gradient)const {
        gradData[ADHelper<Level, Nvars>::GetDataSize(Level - GradLevel, baseCount) + index + ID] += gradient;
    }
};

template<unsigned Nvars>
struct ADVariable<0, Nvars> {
    static const unsigned CurrentSize = 1;
    static const unsigned TotalSize = 0;
};

#endif  // ADVARIABLE_H
