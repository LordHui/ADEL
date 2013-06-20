#ifndef COSH_H
#define COSH_H

template<typename R>
struct Cosh : StaticInterface<Cosh<R>>, UnaryOperation<R> {
    INLINE_MODE
    Cosh(const R& right):
        UnaryOperation(right, cosh(right.Value)) {}

    template<unsigned GradLevel, typename T>INLINE_MODE
    void Gradient(real gradData[], unsigned index, const unsigned baseCount, const T& gradient)const {
        Right.Gradient<GradLevel>(gradData, index, baseCount, gradient * sinh(Right));
    }

    template<>INLINE_MODE
    void Gradient<1>(real gradData[], unsigned index, const unsigned baseCount, const real& gradient)const {
        Right.Gradient<1>(gradData, index, baseCount, gradient * sinh(Right.Value));
    }
};

template<typename R>INLINE_MODE
const Cosh<R> cosh(const StaticInterface<R>& right) {
    return Cosh<R>(right.Self());
}

#endif  // COSH_H
