#ifndef ADD_H
#define ADD_H

template<typename L, typename R>
struct Add : StaticInterface<Add<L, R>>, BinaryOperation<L, R> {
    INLINE_MODE
    Add(const L& left, const R& right):
        BinaryOperation(left, right, left.Value + right.Value) {}

    template<unsigned GradLevel, typename T>INLINE_MODE
    void Gradient(real gradData[], unsigned index, const unsigned baseCount, const T& gradient)const {
        Left.Gradient<GradLevel>(gradData, index, baseCount, gradient);
        Right.Gradient<GradLevel>(gradData, index, baseCount, gradient);
    }
};

template<typename L, typename R>INLINE_MODE
const Add<L, R> operator +(const StaticInterface<L>& left, const StaticInterface<R>& right) {
    return Add<L, R>(left.Self(), right.Self());
}

template<typename R>
struct Add<real, R> : StaticInterface<Add<real, R>>, BinaryOperation<real, R> {
    INLINE_MODE
    Add(const real& left, const R& right):
        BinaryOperation(left, right, left + right.Value) {}

    template<unsigned GradLevel, typename T>INLINE_MODE
    void Gradient(real gradData[], unsigned index, const unsigned baseCount, const T& gradient)const {
        Right.Gradient<GradLevel>(gradData, index, baseCount, gradient);
    }
};

template<typename R>INLINE_MODE
const Add<real, R> operator +(const real& left, const StaticInterface<R>& right) {
    return Add<real, R>(left, right.Self());
}

template<typename L>
struct Add<L, real> : StaticInterface<Add<L, real>>, BinaryOperation<L, real> {
    INLINE_MODE
    Add(const L& left, const real& right):
        BinaryOperation(left, right, left.Value + right) {}

    template<unsigned GradLevel, typename T>INLINE_MODE
    void Gradient(real gradData[], unsigned index, const unsigned baseCount, const T& gradient)const {
        Left.Gradient<GradLevel>(gradData, index, baseCount, gradient);
    }
};

template<typename L>INLINE_MODE
const Add<L, real> operator +(const StaticInterface<L>& left, const real& right) {
    return Add<L, real>(left.Self(), right);
}

#endif  // ADD_H
