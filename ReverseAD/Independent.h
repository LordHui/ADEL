#ifndef INDEPENDENT_H
#define INDEPENDENT_H

template<unsigned Level, int Nvars>
struct Independent : StaticInterface<Independent<Level, Nvars>> {
    int ID;
    real Value;

    INLINE_MODE
    Independent<Level, Nvars>(): Value(0.0) {}

    INLINE_MODE
    Independent<Level, Nvars>(const real& value): Value(value) {}

    template<unsigned GradLevel>INLINE_MODE
    void ComputeGradient(real gradData[], unsigned index, const unsigned size)const {
        gradData[ADVariable<Level, Nvars>::GetSize(Level - GradLevel, size) + index + ID] += 1.0;
    }

#if defined STACK_BASED
    template<unsigned GradLevel, typename T>INLINE_MODE
    void PropagateTGradient(real gradData[], unsigned index, const unsigned size, const T& gradient)const {
        gradData[ADVariable<Level, Nvars>::GetSize(Level - GradLevel, size) + index + ID] += gradient.Self().Value;
        gradient.Self().ComputeGradient < GradLevel - 1 > (gradData, (index + ID) * size, size);
    }

    template<unsigned GradLevel>INLINE_MODE
    void PropagateRGradient(real gradData[], unsigned index, const unsigned size, const real& gradient)const {
        gradData[ADVariable<Level, Nvars>::GetSize(Level - GradLevel, size) + index + ID] += gradient;
    }

#else
    template<unsigned GradLevel, typename T>INLINE_MODE
    void PropagateGradient(real gradData[], unsigned index, const unsigned size, const T& gradient)const {
        gradData[ADVariable<Level, Nvars>::GetSize(Level - GradLevel, size) + index + ID] += gradient.Self().Value;
        gradient.Self().PropagateGradient < GradLevel - 1 > (gradData, (index + ID) * size, size, 1.0);
    }

    template<unsigned GradLevel>INLINE_MODE
    void PropagateGradient(real gradData[], unsigned index, const unsigned size, const real& gradient)const {
        gradData[ADVariable<Level, Nvars>::GetSize(Level - GradLevel, size) + index + ID] += gradient;
    }
#endif

    template<unsigned Level, int Nvars>INLINE_MODE
    void GetDependencies(std::vector<const ADVariable<Level, Nvars>*>& dependencies)const {}
};

#endif  // INDEPENDENT_H
