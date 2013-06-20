#ifndef POW_H
#define POW_H

template<typename B, typename E>
struct Pow : StaticInterface<Pow<B, E>>, BinaryOperation<B, E> {
    INLINE_MODE
    Pow(const B& base, const E& exponent):
        BinaryOperation(base, exponent, pow(base.Value, exponent.Value)) {}

    template<unsigned GradLevel, typename T>INLINE_MODE
    void Gradient(real gradData[], unsigned index, const unsigned baseCount, const T& gradient)const {
        Left.Gradient<GradLevel>(gradData, index, baseCount, (*this) * Right * gradient / Left);
        Right.Gradient<GradLevel>(gradData, index, baseCount, (*this) * log(Left) * gradient);
    }

    template<>INLINE_MODE
    void Gradient<1>(real gradData[], unsigned index, const unsigned baseCount, const real& gradient)const {
        Left.Gradient<1>(gradData, index, baseCount, Value * Right.Value * gradient / Left.Value);
        Right.Gradient<1>(gradData, index, baseCount, Value * log(Left.Value) * gradient);
    }
};

template<typename B, typename E>INLINE_MODE
const Pow<B, E> pow(const StaticInterface<B>& base, const StaticInterface<E>& exponent) {
    return Pow<B, E>(base.Self(), exponent.Self());
}

template<typename E>
struct Pow<real, E> : StaticInterface<Pow<real, E>>, BinaryOperation<real, E> {
    INLINE_MODE
    Pow(const real& base, const E& exponent):
        BinaryOperation(base, exponent, pow(base, exponent.Value)) {}

    template<unsigned GradLevel, typename T>INLINE_MODE
    void Gradient(real gradData[], unsigned index, const unsigned baseCount, const T& gradient)const {
        Right.Gradient<GradLevel>(gradData, index, baseCount, (*this) * log(Left) * gradient);
    }

    template<>INLINE_MODE
    void Gradient<1>(real gradData[], unsigned index, const unsigned baseCount, const real& gradient)const {
        Right.Gradient<1>(gradData, index, baseCount, Value * log(Left) * gradient);
    }
};

template<typename E>INLINE_MODE
const Pow<real, E> pow(const real& base, const StaticInterface<E>& exponent) {
    return Pow<real, E>(base, exponent.Self());
}

template<typename B>
struct Pow<B, real> : StaticInterface<Pow<B, real>>, BinaryOperation<B, real> {
    INLINE_MODE
    Pow(const B& base, const real& exponent):
        BinaryOperation(base, exponent, pow(base.Value, exponent)) {}

    template<unsigned GradLevel, typename T>INLINE_MODE
    void Gradient(real gradData[], unsigned index, const unsigned baseCount, const T& gradient)const {
        Left.Gradient<GradLevel>(gradData, index, baseCount, (*this) * Right * gradient / Left);
    }

    template<>INLINE_MODE
    void Gradient<1>(real gradData[], unsigned index, const unsigned baseCount, const real& gradient)const {
        Left.Gradient<1>(gradData, index, baseCount, Value * Right * gradient / Left.Value);
    }
};

template<typename B>INLINE_MODE
const Pow<B, real> pow(const StaticInterface<B>& base, const real& exponent) {
    return Pow<B, real>(base.Self(), exponent);
}

#endif  // POW_H
