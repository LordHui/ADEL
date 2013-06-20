#ifndef ATAN_H
#define ATAN_H

template<typename R>
struct Atan : StaticInterface<Atan<R>>, UnaryOperation<R> {
    INLINE_MODE
    Atan(const R& right):
        UnaryOperation(right, atan(right.Value)) {}

    template<unsigned GradLevel, typename T>INLINE_MODE
    void Gradient(real gradData[], unsigned index, const unsigned baseCount, const T& gradient)const {
        Right.Gradient<GradLevel>(gradData, index, baseCount, gradient / (1.0 + sqr(Right)));
    }

    template<>INLINE_MODE
    void Gradient<1>(real gradData[], unsigned index, const unsigned baseCount, const real& gradient)const {
        Right.Gradient<1>(gradData, index, baseCount, gradient / (1.0 + sqr(Right.Value)));
    }
};

template<typename R>INLINE_MODE
const Atan<R> atan(const StaticInterface<R>& right) {
    return Atan<R>(right.Self());
}

#endif  // ATAN_H
