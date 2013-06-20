#ifndef LOG_H
#define LOG_H

template<typename R>
struct Log : StaticInterface<Log<R>>, UnaryOperation<R> {
    INLINE_MODE
    Log(const R& right):
        UnaryOperation(right, log(right.Value)) {}

    template<unsigned GradLevel, typename T>INLINE_MODE
    void Gradient(real gradData[], unsigned index, const unsigned baseCount, const T& gradient)const {
        Right.Gradient<GradLevel>(gradData, index, baseCount, gradient / Right);
    }

    template<>INLINE_MODE
    void Gradient<1>(real gradData[], unsigned index, const unsigned baseCount, const real& gradient)const {
        Right.Gradient<1>(gradData, index, baseCount, gradient / Right.Value);
    }
};

template<typename R>INLINE_MODE
const Log<R> log(const StaticInterface<R>& right) {
    return Log<R>(right.Self());
}

#endif  // LOG_H
