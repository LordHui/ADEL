#ifndef MUL_H
#define MUL_H

template<typename L, typename R>
struct Mul : StaticInterface<Mul<L, R>>, BinaryOperation<L, R> {
    INLINE_MODE
    Mul(const L& left, const R& right):
        BinaryOperation(left, right, left.Value* right.Value) {}

    template<unsigned GradLevel, typename T>INLINE_MODE
    void Gradient(real gradData[], unsigned index, const unsigned baseCount, const T& gradient)const {
        Left.Gradient<GradLevel>(gradData, index, baseCount, gradient * Right);
        Right.Gradient<GradLevel>(gradData, index, baseCount, Left * gradient);
    }

    template<>INLINE_MODE
    void Gradient<1>(real gradData[], unsigned index, const unsigned baseCount, const real& gradient)const {
        Left.Gradient<1>(gradData, index, baseCount, gradient * Right.Value);
        Right.Gradient<1>(gradData, index, baseCount, Left.Value * gradient);
    }
};

template<typename L, typename R>INLINE_MODE
const Mul<L, R> operator *(const StaticInterface<L>& left, const StaticInterface<R>& right) {
    return Mul<L, R>(left.Self(), right.Self());
}

template<typename R>
struct Mul<real, R> : StaticInterface<Mul<real, R>>, BinaryOperation<real, R> {
    INLINE_MODE
    Mul(const real& left, const R& right):
        BinaryOperation(left, right, left* right.Value) {}

    template<unsigned GradLevel, typename T>INLINE_MODE
    void Gradient(real gradData[], unsigned index, const unsigned baseCount, const T& gradient)const {
        Right.Gradient<GradLevel>(gradData, index, baseCount, Left * gradient);
    }
};

template<typename R>INLINE_MODE
const Mul<real, R> operator *(const real& left, const StaticInterface<R>& right) {
    return Mul<real, R>(left, right.Self());
}

template<typename L>
struct Mul<L, real> : StaticInterface<Mul<L, real>>, BinaryOperation<L, real> {
    INLINE_MODE
    Mul(const L& left, const real& right):
        BinaryOperation(left, right, left.Value* right) {}

    template<unsigned GradLevel, typename T>INLINE_MODE
    void Gradient(real gradData[], unsigned index, const unsigned baseCount, const T& gradient)const {
        Left.Gradient<GradLevel>(gradData, index, baseCount, gradient * Right);
    }
};

template<typename L>INLINE_MODE
const Mul<L, real> operator *(const StaticInterface<L>& left, const real& right) {
    return Mul<L, real>(left.Self(), right);
}

#endif  // MUL_H
