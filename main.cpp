#include <math.h>
#ifndef _BCIS
#define _BCIS
template <class ItemType>
class BCIS
{
  private:
    static void SWAP(ItemType *theArray, int i, int j);
    static void INSRIGHT(ItemType *theArray, ItemType CurrItem, int SR, int right);
    static void INSLEFT(ItemType *theArray, ItemType CurrItem, int SL, int left);
    static int ISEQUAL(ItemType *theArray, int SL, int SR);

  public:
    BCIS();
    static int Sort(ItemType *theArray, int left, int right);
};

template <class ItemType>
BCIS<ItemType>::BCIS(){};

template <class ItemType>
void BCIS<ItemType>::SWAP(ItemType *theArray, int i, int j)
{
    ItemType Temp = theArray[i]; // store value at i-index so it does not get over written.
    theArray[i] = theArray[j];   // set value at j-index to i-index.
    theArray[j] = Temp;          // set the temp to j-index.
};
template <class ItemType>
void BCIS<ItemType>::INSRIGHT(ItemType *theArray, ItemType CurrItem, int SR, int right)
{
    int j = SR;
    while (j <= right && CurrItem > theArray[j])
    {
        theArray[j - 1] = theArray[j];
        j = j + 1;
    };
    theArray[j - 1] = CurrItem;
};
template <class ItemType>
void BCIS<ItemType>::INSLEFT(ItemType *theArray, ItemType CurrItem, int SL, int left)
{
    int j = SL;
    while (j >= left && CurrItem < theArray[j])
    {
        theArray[j + 1] = theArray[j];
        j = j - 1;
    };
    theArray[j + 1] = CurrItem;
};
template <class ItemType>
int BCIS<ItemType>::ISEQUAL(ItemType *theArray, int SL, int SR)
{
    int SL_MORE = SL + 1;
    int SR_LESS = SR - 1;
    for (int k = SL_MORE; k <= SR_LESS; k++)
    {
        if (theArray[k] != theArray[SL])
        {
            SWAP(theArray, k, SL);
            return k;
        }
    }
    return -1;
};
template <class ItemType>
int BCIS<ItemType>::Sort(ItemType *theArray, int left, int right)
{
    int SL = left;  // this is the index of the sorted left list
    int SR = right; // this is the index of the sorted right list
    int i;
    while (SL < SR && SR <= right)
    {
        int calc_1 = SL + ((SR - SL) / 2);
        SWAP(theArray, SR, calc_1);
        if (theArray[SL] == theArray[SR])
        {
            if (ISEQUAL(theArray, SL, SR) != -1)
            {
                return -1;
            }
        }
        if (theArray[SL] > theArray[SR])
        {
            SWAP(theArray, SL, SR);
        }
        if (SL - SR >= 100)
        {
            for (i = (SL + 1); i <= sqrt(SR - SL); i++)
            {
                if (theArray[SR] < theArray[i])
                {
                    SWAP(theArray, SR, i);
                }
                else if (theArray[SL] > theArray[i])
                {
                    SWAP(theArray, SL, i);
                }
            }
        }
        else
        {
            i = SL + 1;
        }
        ItemType LC = theArray[SL];
        ItemType RC = theArray[SR];
        while (i < SR)
        {
            ItemType CurrentItem = theArray[i];
            if (CurrentItem >= RC)
            {
                theArray[i] = theArray[SR - 1];
                INSRIGHT(theArray, CurrentItem, SR, right);
                SR = SR - 1;
            }
            else if (CurrentItem <= LC)
            {
                theArray[i] = theArray[SL + 1];
                INSLEFT(theArray, CurrentItem, SL, left);
                SL = SL + 1;
                i = i + 1;
            }
            else
            {
                i = i + 1;
            }
        }
        SL = SL + 1;
        SR = SR + 1;
    };
    return 1;
};
#endif

