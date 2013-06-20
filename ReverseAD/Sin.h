#ifndef SIN_H
#define SIN_H

template<typename R>
struct Sin : StaticInterface<Sin<R>>, UnaryOperation<R> {
    INLINE_MODE
    Sin(const R& right):
        UnaryOperation(right, sin(right.Value)) {}

    template<unsigned GradLevel, typename T>INLINE_MODE
    void Gradient(real gradData[], unsigned index, const unsigned baseCount, const T& gradient)const {
        Right.Gradient<GradLevel>(gradData, index, baseCount, gradient * cos(Right));
    }

    template<>INLINE_MODE
    void Gradient<1>(real gradData[], unsigned index, const unsigned baseCount, const real& gradient)const {
        Right.Gradient<1>(gradData, index, baseCount, gradient * cos(Right.Value));
    }
};

template<typename R>INLINE_MODE
const Sin<R> sin(const StaticInterface<R>& right) {
    return Sin<R>(right.Self());
}

#endif  // SIN_H
