#pragma once

namespace Util
{
    template <class T>
    T setAndGetOld (const T& newValue, T* currentValue)
    {
        T oldValue = *currentValue;
        *currentValue = newValue;
        return oldValue;
    }
}