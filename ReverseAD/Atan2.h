#ifndef ATAN2_H
#define ATAN2_H

template<typename L, typename R>
struct Atan2 : StaticInterface<Atan2<L, R>>, BinaryOperation<L, R> {
    INLINE_MODE
    Atan2(const L& left, const R& right):
        BinaryOperation(left, right, atan2(left.Value, right.Value)) {}

    template<unsigned GradLevel, typename T>INLINE_MODE
    void Gradient(real gradData[], unsigned index, const unsigned baseCount, const T& gradient)const {
        Left.Gradient<GradLevel>(gradData, index, baseCount, gradient * Right / (sqr(Left) + sqr(Right)));
        Right.Gradient<GradLevel>(gradData, index, baseCount, -gradient * Left / (sqr(Left) + sqr(Right)));
    }

    template<>INLINE_MODE
    void Gradient<1>(real gradData[], unsigned index, const unsigned baseCount, const real& gradient)const {
        Left.Gradient<1>(gradData, index, baseCount, gradient * Right.Value / (sqr(Left.Value) + sqr(Right.Value)));
        Right.Gradient<1>(gradData, index, baseCount, -gradient * Left.Value / (sqr(Left.Value) + sqr(Right.Value)));
    }
};

template<typename L, typename R>INLINE_MODE
const Atan2<L, R> atan2(const StaticInterface<L>& left, const StaticInterface<R>& right) {
    return Atan2<L, R>(left.Self(), right.Self());
}

template<typename R>
struct Atan2<real, R> : StaticInterface<Atan2<real, R>>, BinaryOperation<real, R> {
    INLINE_MODE
    Atan2(const real& left, const R& right):
        BinaryOperation(left, right, atan2(left, right.Value)) {}

    template<unsigned GradLevel, typename T>INLINE_MODE
    void Gradient(real gradData[], unsigned index, const unsigned baseCount, const T& gradient)const {
        Right.Gradient<GradLevel>(gradData, index, baseCount, -gradient * Left / (sqr(Left) + sqr(Right)));
    }

    template<>INLINE_MODE
    void Gradient<1>(real gradData[], unsigned index, const unsigned baseCount, const real& gradient)const {
        Right.Gradient<1>(gradData, index, baseCount, -gradient * Left / (sqr(Left) + sqr(Right.Value)));
    }
};

template<typename R>INLINE_MODE
const Atan2<real, R> atan2(const real& left, const StaticInterface<R>& right) {
    return Atan2<real, R>(left, right.Self());
}

template<typename L>
struct Atan2<L, real> : StaticInterface<Atan2<L, real>>, BinaryOperation<L, real> {
    INLINE_MODE
    Atan2(const L& left, const real& right):
        BinaryOperation(left, right, atan2(left.Value, right)) {}

    template<unsigned GradLevel, typename T>INLINE_MODE
    void Gradient(real gradData[], unsigned index, const unsigned baseCount, const T& gradient)const {
        Left.Gradient<GradLevel>(gradData, index, baseCount, gradient * Right / (sqr(Left) + sqr(Right)));
    }

    template<>INLINE_MODE
    void Gradient<1>(real gradData[], unsigned index, const unsigned baseCount, const real& gradient)const {
        Left.Gradient<1>(gradData, index, baseCount, gradient * Right / (sqr(Left.Value) + sqr(Right)));
    }
};

template<typename L>INLINE_MODE
const Atan2<L, real> atan2(const StaticInterface<L>& left, const real& right) {
    return Atan2<L, real>(left.Self(), right);
}

#endif  // ATAN2_H
