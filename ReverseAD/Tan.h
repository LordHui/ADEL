#ifndef TAN_H
#define TAN_H

template<typename R>
struct Tan : StaticInterface<Tan<R>>, UnaryOperation<R> {
    INLINE_MODE
    Tan(const R& right):
        UnaryOperation(right, tan(right.Value)) {}

    template<unsigned GradLevel, typename T>INLINE_MODE
    void Gradient(real gradData[], unsigned index, const unsigned baseCount, const T& gradient)const {
        Right.Gradient<GradLevel>(gradData, index, baseCount, gradient * (1.0 + sqr(*this)));
    }

    template<>INLINE_MODE
    void Gradient<1>(real gradData[], unsigned index, const unsigned baseCount, const real& gradient)const {
        Right.Gradient<1>(gradData, index, baseCount, gradient * (1.0 + sqr(Value)));
    }
};

template<typename R>INLINE_MODE
const Tan<R> tan(const StaticInterface<R>& right) {
    return Tan<R>(right.Self());
}

#endif  // TAN_H
