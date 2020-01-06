#ifndef _RENDER_H_
#define _RENDER_H_

#include "gameOfLifeEngine/grid.h"

typedef void (voidFn)(void);
typedef void (displayCellFn)(struct Point point, char mark);
#define CALL_MEMBER_FN(object,ptrToMember)  ((object).*(ptrToMember))

struct displayFunctionPointers {
    // void (*preDisplayFunction)(void); 
    // void (*endRowFunction)(void); 
    // void (*postDisplayFunction)(void); 

    voidFn* preDisplayFunction; 
    voidFn* endRowFunction; 
    voidFn* postDisplayFunction; 

    // void (*displayCellFunction)(struct Point point, char mark);
    displayCellFn* displayCellFunction;
};
/*
void userCode(Fred& fred, FredMemFn p)  // Use a typedef for pointer-to-member types
{
  int ans = std::invoke(p, fred, 'x', 3.14);
  // Would normally be: int ans = (fred.*p)('x', 3.14);
  // ...

  #define CALL_MEMBER_FN(object,ptrToMember)  ((object).*(ptrToMember))
  void userCode(Fred& fred, FredMemFn p)  // Use a typedef for pointer-to-member types
{
  int ans = CALL_MEMBER_FN(fred,p)('x', 3.14);
  // Would normally be: int ans = (fred.*p)('x', 3.14);
  // ...
}
}
*/

void display(struct Grid grid, struct displayFunctionPointers displayFunctionPointers);

#endif