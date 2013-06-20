#ifndef DEPENDENT_H
#define DEPENDENT_H

#include <string>

template<unsigned Level, unsigned Nvars>
struct Dependent {
    static const unsigned CurrentSize = Dependent < Level - 1, Nvars >::CurrentSize* Nvars;
    static const unsigned TotalSize = Dependent < Level - 1, Nvars >::TotalSize + CurrentSize;

    real Data[TotalSize];

    INLINE_MODE
    Dependent() {
        memset(&Data, 0, TotalSize * sizeof(real));
    };

    template<typename R>INLINE_MODE
    Dependent(const StaticInterface<R>& expression) {
        memset(&Data, 0, TotalSize * sizeof(real));
        Data[0] = expression.Self().Value;
        expression.Self().ComputeGradient<Level>(Data, 0, Nvars);
    };

    template<typename R>INLINE_MODE
    Dependent& operator=(const StaticInterface<R>& expression) {
        memset(&Data, 0, TotalSize * sizeof(real));
        Data[0] = expression.Self().Value;
        expression.Self().ComputeGradient<Level>(Data, 0, Nvars);
        return *this;
    };

    INLINE_MODE
    Dependent(const real& value) {
        memset(&Data, 0, TotalSize * sizeof(real));
        Data[0] = value;
    };

    INLINE_MODE
    Dependent& operator=(const real& value) {
        memset(&Data, 0, TotalSize * sizeof(real));
        Data[0] = value;
        return *this;
    };

    INLINE_MODE
    real Value() {
        return Data[0];
    }

    INLINE_MODE
    real Gradient(unsigned i) {
        return Data[Dependent<0, Nvars>::TotalSize + i];
    }

    INLINE_MODE
    real Hessian(unsigned i, unsigned j) {
        return Data[Dependent<1, Nvars>::TotalSize + i * Nvars + j];
    }
};

template<unsigned Nvars>
struct Dependent<0, Nvars> {
    static const unsigned CurrentSize = 1;
    static const unsigned TotalSize = 1;
};

#endif  // DEPENDENT_H
