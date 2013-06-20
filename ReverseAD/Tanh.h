#ifndef TANH_H
#define TANH_H

template<typename R>
struct Tanh : StaticInterface<Tanh<R>>, UnaryOperation<R> {
    INLINE_MODE
    Tanh(const R& right):
        UnaryOperation(right, tanh(right.Value)) {}

    template<unsigned GradLevel, typename T>INLINE_MODE
    void Gradient(real gradData[], unsigned index, const unsigned baseCount, const T& gradient)const {
        Right.Gradient<GradLevel>(gradData, index, baseCount, gradient * (1.0 - sqr(*this)));
    }

    template<>INLINE_MODE
    void Gradient<1>(real gradData[], unsigned index, const unsigned baseCount, const real& gradient)const {
        Right.Gradient<1>(gradData, index, baseCount, gradient * (1.0 - sqr(Value)));
    }
};

template<typename R>INLINE_MODE
const Tanh<R> tanh(const StaticInterface<R>& right) {
    return Tanh<R>(right.Self());
}

#endif  // TANH_H
