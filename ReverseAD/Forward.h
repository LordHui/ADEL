#ifndef FORWARD_H
#define FORWARD_H

template<int MaxLevel, int Nvars>
struct Forward {
    Forward < MaxLevel - 1, Nvars > Value;
    Forward < MaxLevel - 1, Nvars > Gradient[Nvars];

    Forward() {};

    Forward(const Dependent<MaxLevel, Nvars>& dependent) {
        Initialize<0>(dependent.Data, 0);
    };

    template<int Level> INLINE_MODE
    void Initialize(const real data[], int index) {
        Value.Initialize<Level>(data, index);
        for (int i = 0; i < Nvars; i++)
            Gradient[i].Initialize < Level + 1 > (data, index * Nvars + i);
    };

    Dependent<MaxLevel, Nvars> Convert() {
        Dependent<MaxLevel, Nvars> result;
        Get<0>(result.Data, 0);
        return result;
    }

    template<int Level> INLINE_MODE
    void Get(real data[], int index) {
        Value.Get<Level>(data, index);
        for (int i = 0; i < Nvars; i++)
            Gradient[i].Get < Level + 1 > (data, index * Nvars + i);
    };
};

template<int Nvars>
struct Forward<1, Nvars>
{
    real Value;
    real Gradient[Nvars];

    Forward() {};

    Forward(const Dependent<1, Nvars>& dependent) {
        Value = dependent.Data[0];
        for (int i = 0; i < Nvars; i++)
            Gradient[i] = dependent.Data[i + 1];
    };

    template<int Level> INLINE_MODE
    void Initialize(const real data[], int index) {
        Value = data[Dependent < Level - 1, Nvars >::TotalSize + index];
        for (int i = 0; i < Nvars; i++)
            Gradient[i] = data[Dependent<Level, Nvars>::TotalSize + index * Nvars + i];
    };

    Dependent<1, Nvars> Convert() {
        Dependent<1, Nvars> result;
        result.Data[0]  = Value;
        for (int i = 0; i < Nvars; i++)
            result.Data[i + 1] = Gradient[i] ;
        return result;
    }

    template<int Level> INLINE_MODE
    void Get(real data[], int index) {
        data[Dependent < Level - 1, Nvars >::TotalSize + index] = Value;
        for (int i = 0; i < Nvars; i++)
            data[Dependent<Level, Nvars>::TotalSize + index * Nvars + i] = Gradient[i];
    };
};

#endif  // FORWARD_H
