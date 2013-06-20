#ifndef DIV_H
#define DIV_H

template<typename L, typename R>
struct Div : StaticInterface<Div<L, R>>, BinaryOperation<L, R> {
    INLINE_MODE
    Div(const L& left, const R& right):
        BinaryOperation(left, right, left.Value / right.Value) {}

    template<unsigned GradLevel, typename T>INLINE_MODE
    void Gradient(real gradData[], unsigned index, const unsigned baseCount, const T& gradient)const {
        Left.Gradient<GradLevel>(gradData, index, baseCount, gradient / Right);
        Right.Gradient<GradLevel>(gradData, index, baseCount, -(gradient * Left) / sqr(Right));
    }

    template<>INLINE_MODE
    void Gradient<1>(real gradData[], unsigned index, const unsigned baseCount, const real& gradient)const {
        Left.Gradient<1>(gradData, index, baseCount, gradient / Right.Value);
        Right.Gradient<1>(gradData, index, baseCount, -(gradient * Left.Value) / sqr(Right.Value));
    }
};

template<typename L, typename R>INLINE_MODE
const Div<L, R> operator /(const StaticInterface<L>& left, const StaticInterface<R>& right) {
    return Div<L, R>(left.Self(), right.Self());
}

template<typename R>
struct Div<real, R> : StaticInterface<Div<real, R>>, BinaryOperation<real, R> {
    INLINE_MODE
    Div(const real& left, const R& right):
        BinaryOperation(left, right, left / right.Value) {}

    template<unsigned GradLevel, typename T>INLINE_MODE
    void Gradient(real gradData[], unsigned index, const unsigned baseCount, const T& gradient)const {
        Right.Gradient<GradLevel>(gradData, index, baseCount, -(gradient * Left) / sqr(Right));
    }

    template<>INLINE_MODE
    void Gradient<1>(real gradData[], unsigned index, const unsigned baseCount, const real& gradient)const {
        Right.Gradient<1>(gradData, index, baseCount, -(gradient * Left) / sqr(Right.Value));
    }
};

template<typename R>INLINE_MODE
const Div<real, R> operator /(const real& left, const StaticInterface<R>& right) {
    return Div<real, R>(left, right.Self());
}

template<typename L>
struct Div<L, real> : StaticInterface<Div<L, real>>, BinaryOperation<L, real> {
    INLINE_MODE
    Div(const L& left, const real& right):
        BinaryOperation(left, right, left.Value / right) {}

    template<unsigned GradLevel, typename T>INLINE_MODE
    void Gradient(real gradData[], unsigned index, const unsigned baseCount, const T& gradient)const {
        Left.Gradient<GradLevel>(gradData, index, baseCount, gradient / Right);
    }
};

template<typename L>INLINE_MODE
const Div<L, real> operator /(const StaticInterface<L>& left, const real& right) {
    return Div<L, real>(left.Self(), right);
}

#endif  // DIV_H
