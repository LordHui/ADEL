#include <stdio.h>

#include "test_common.h"
#include "test_4ad.h"
#include "test_2_10.h"

int main()
{
	bool result = true;
	verify_test_result(result, "test_taylor_2_10", test_tailor_2_10());
    verify_test_result(result, "test_4ad", test_4ad());

	return result;
}