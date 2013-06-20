#ifndef OFFSET_H
#define OFFSET_H

template<int Level, int Nvars>
struct Offset {
    static const int CurrentSize = Offset < Level - 1, Nvars >::CurrentSize* Nvars;
    static const int TotalSize = Offset < Level - 1, Nvars >::TotalSize + CurrentSize;
};

template<int Nvars>
struct Offset<0, Nvars> {
    static const int CurrentSize = 1;
    static const int TotalSize = 1;
};

#endif  // OFFSET_H
