#ifndef SINH_H
#define SINH_H

template<typename R>
struct Sinh : StaticInterface<Sinh<R>>, UnaryOperation<R> {
    INLINE_MODE
    Sinh(const R& right):
        UnaryOperation(right, sinh(right.Value)) {}

    template<unsigned GradLevel, typename T>INLINE_MODE
    void Gradient(real gradData[], unsigned index, const unsigned baseCount, const T& gradient)const {
        Right.Gradient<GradLevel>(gradData, index, baseCount, gradient * cosh(Right));
    }

    template<>INLINE_MODE
    void Gradient<1>(real gradData[], unsigned index, const unsigned baseCount, const real& gradient)const {
        Right.Gradient<1>(gradData, index, baseCount, gradient * cosh(Right.Value));
    }
};

template<typename R>INLINE_MODE
const Sinh<R> sinh(const StaticInterface<R>& right) {
    return Sinh<R>(right.Self());
}

#endif  // SINH_H
