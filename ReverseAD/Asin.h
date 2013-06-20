#ifndef ASIN_H
#define ASIN_H

template<typename R>
struct Asin : StaticInterface<Asin<R>>, UnaryOperation<R> {
    INLINE_MODE
    Asin(const R& right):
        UnaryOperation(right, asin(right.Value)) {}

    template<unsigned GradLevel, typename T>INLINE_MODE
    void Gradient(real gradData[], unsigned index, const unsigned baseCount, const T& gradient)const {
        Right.Gradient<GradLevel>(gradData, index, baseCount, gradient / sqrt(1.0 - sqr(Right)));
    }

    template<>INLINE_MODE
    void Gradient<1>(real gradData[], unsigned index, const unsigned baseCount, const real& gradient)const {
        Right.Gradient<1>(gradData, index, baseCount, gradient / sqrt(1.0 - sqr(Right.Value)));
    }
};

template<typename R>INLINE_MODE
const Asin<R> asin(const StaticInterface<R>& right) {
    return Asin<R>(right.Self());
}

#endif  // ASIN_H
