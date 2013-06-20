#ifndef SQR_H
#define SQR_H

template<typename R>
struct Sqr : StaticInterface<Sqr<R>>, UnaryOperation<R> {
    INLINE_MODE
    Sqr(const R& right):
        UnaryOperation(right, right.Value* right.Value) {}

    template<unsigned GradLevel, typename T>INLINE_MODE
    void Gradient(real gradData[], unsigned index, const unsigned baseCount, const T& gradient)const {
        Right.Gradient<GradLevel>(gradData, index, baseCount, 2.0 * gradient * Right);
    }

    template<>INLINE_MODE
    void Gradient<1>(real gradData[], unsigned index, const unsigned baseCount, const real& gradient)const {
        Right.Gradient<1>(gradData, index, baseCount, 2.0 * gradient * Right.Value);
    }
};

template<typename R>INLINE_MODE
const Sqr<R> sqr(const StaticInterface<R>& right) {
    return Sqr<R>(right.Self());
}

real sqr(const real& right) {
    return right * right;
}

#endif  // SQR_H
