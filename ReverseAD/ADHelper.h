#ifndef ADHELPER_H
#define ADHELPER_H

template<unsigned Level, unsigned Nvars>
struct ADVariable;

template<unsigned Level, unsigned Nvars>
struct ADHelper {
    static unsigned GetDataSize(unsigned level, unsigned nvars) {
        unsigned totalSize = 0;
        unsigned currentSize = 1;
        for (unsigned i = 0; i < level; i++) {
            currentSize *= nvars;
            totalSize += currentSize;
        }
        return totalSize;
    }

    template<unsigned InjectionLevel>
    static void Inject(const std::vector<const ADVariable<Level, Nvars>*>& dependencies, const real from[], real to[]) {
        Inject < InjectionLevel - 1 > (dependencies, from, to);
    }

    template<>
    static void Inject<2>(const std::vector<const ADVariable<Level, Nvars>*>& dependencies, const real from[], real to[]) {
        unsigned tmpCount = static_cast<unsigned>(dependencies.size());
        unsigned totalCount = Nvars + tmpCount;
        for (unsigned x = 0; x < tmpCount; x++) {
            unsigned xID = dependencies[x]->ID;
            unsigned d2X_ = totalCount + xID * totalCount;
            const real* xData = dependencies[x]->Data;
            for (unsigned i = 0; i < Nvars; i++) {
                unsigned d2i_ = Nvars + i * Nvars;
                unsigned d2IX = totalCount + i * totalCount + xID;
                for (unsigned j = i; j < Nvars; j++) {
                    real sum = 0;
                    for (unsigned y = 0; y < tmpCount; y++)
                        sum += from[d2X_ + dependencies[y]->ID] * dependencies[y]->Data[j];
                    sum += from[d2X_ + j];
                    sum *= xData[i];
                    sum += from[d2IX] * xData[j];
                    sum += from[xID] * xData[d2i_ + j];
                    to[d2i_ + j] += sum;
                }
                for (unsigned j = 0; j < i; j++)
                    to[d2i_ + j] = to[Nvars + j * Nvars + i];
            }
        }
        Inject<1> (dependencies, from, to);
    }

    template<>
    static void Inject<1>(const std::vector<const ADVariable<Level, Nvars>*>& dependencies, const real from[], real to[]) {
        unsigned tmpCount = static_cast<unsigned>(dependencies.size());
        for (unsigned x = 0; x < tmpCount; x++) {
            unsigned xID = dependencies[x]->ID;
            const real* xData = dependencies[x]->Data;
            for (unsigned i = 0; i < Nvars; i++)
                to[i] += from[xID] * xData[i];
        }
    }

    template<unsigned CropLevel>
    static void Crop(const real from[], real to[], unsigned fromIndex, unsigned toIndex, unsigned tmpCount) {
        unsigned totalCount = Nvars + tmpCount;
        unsigned toOffset = GetDataSize(Level - CropLevel, Nvars) + toIndex;
        unsigned fromOffset = GetDataSize(Level - CropLevel, totalCount) + fromIndex;
        for (unsigned i = 0; i < Nvars; i++) {
            to[toOffset + i] = from[fromOffset + i];
            Crop < CropLevel - 1 > (from, to, (fromIndex + i) * totalCount, (toIndex + i) * (Nvars), tmpCount);
        }
    }

    template<>
    static void Crop<1>(const real from[], real to[], unsigned fromIndex, unsigned toIndex, unsigned tmpCount) {
        unsigned totalCount = Nvars + tmpCount;
        unsigned toOffset = GetDataSize(Level - 1, Nvars) + toIndex;
        unsigned fromOffset = GetDataSize(Level - 1, totalCount) + fromIndex;
        for (unsigned i = 0; i < Nvars; i++) {
            to[toOffset + i] = from[fromOffset + i];
        }
    }

    template<unsigned MorphLevel, unsigned NewBase>
    struct Morpher {
        static void Morph(const ADVariable<Level, NewBase> (&tmpBase)[Nvars], const real from[], real to[]) {
            Morpher < MorphLevel - 1, NewBase >::Morph(tmpBase, from, to);
        }
    };

    template<unsigned NewBase>
    struct Morpher<2, NewBase> {
        static void Morph(const ADVariable<Level, NewBase> (&tmpBase)[Nvars], const real from[], real to[]) {
            for (unsigned x = 0; x < Nvars; x++) {
                unsigned d2X_ = Nvars + x * Nvars;
                const real* xData = tmpBase[x].Data;
                for (unsigned i = 0; i < NewBase; i++) {
                    unsigned d2i_ = NewBase + i * NewBase;
                    unsigned d2IX = Nvars + i * Nvars + x;
                    for (unsigned j = i; j < NewBase; j++) {
                        real sum = 0;
                        for (unsigned y = 0; y < Nvars; y++)
                            sum += from[d2X_ + y] * tmpBase[y].Data[j];
                        sum *= xData[i];
                        sum += from[x] * xData[d2i_ + j];
                        to[d2i_ + j] += sum;
                    }
                    for (unsigned j = 0; j < i; j++)
                        to[d2i_ + j] = to[NewBase + j * NewBase + i];
                }
            }
            Morpher<1, NewBase>::Morph(tmpBase, from, to);
        }
    };

    template<unsigned NewBase>
    struct Morpher<1, NewBase> {
        static void Morph(const ADVariable<Level, NewBase> (&tmpBase)[Nvars], const real from[], real to[]) {
            for (unsigned x  = 0; x < Nvars; x++) {
                const real* xData = tmpBase[x].Data;
                for (unsigned i = 0; i < NewBase; i++)
                    to[i] += from[x] * xData[i];
            }
        }
    };
};

#endif  // ADHELPER_H
