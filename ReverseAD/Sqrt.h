#ifndef SQRT_H
#define SQRT_H

template<typename R>
struct Sqrt : StaticInterface<Sqrt<R>>, UnaryOperation<R> {
    INLINE_MODE
    Sqrt(const R& right):
        UnaryOperation(right, sqrt(right.Value)) {}

    template<unsigned GradLevel, typename T>INLINE_MODE
    void Gradient(real gradData[], unsigned index, const unsigned baseCount, const T& gradient)const {
        Right.Gradient<GradLevel>(gradData, index, baseCount, 0.5 * gradient / (*this));
    }

    template<>INLINE_MODE
    void Gradient<1>(real gradData[], unsigned index, const unsigned baseCount, const real& gradient)const {
        Right.Gradient<1>(gradData, index, baseCount, 0.5 * gradient / Value);
    }
};

template<typename R>INLINE_MODE
const Sqrt<R> sqrt(const StaticInterface<R>& right) {
    return Sqrt<R>(right.Self());
}

#endif  // SQRT_H
