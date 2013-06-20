#ifndef EXP_H
#define EXP_H

template<typename R>
struct Exp : StaticInterface<Exp<R>>, UnaryOperation<R> {
    INLINE_MODE
    Exp(const R& right):
        UnaryOperation(right, exp(right.Value)) {}

    template<unsigned GradLevel, typename T>INLINE_MODE
    void Gradient(real gradData[], unsigned index, const unsigned baseCount, const T& gradient)const {
        Right.Gradient<GradLevel>(gradData, index, baseCount, gradient * (*this));
    }

    template<>INLINE_MODE
    void Gradient<1>(real gradData[], unsigned index, const unsigned baseCount, const real& gradient)const {
        Right.Gradient<1>(gradData, index, baseCount, gradient * Value);
    }
};

template<typename R>INLINE_MODE
const Exp<R> exp(const StaticInterface<R>& right) {
    return Exp<R>(right.Self());
}

#endif  // EXP_H
