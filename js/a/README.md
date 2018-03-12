# Can `a == 1 && a == 2 && a== 3` ever evaluate to `true`?
Yes.

```javascript
'use strict';

const a = {
    v: 1,
    valueOf: function() {
        return this.v++;
    }
}

if(a == 1 && a == 2 && a == 3) {
    console.log('Ayy!');
}
```
Output: `Ayy!`

[Stack Overflow](https://stackoverflow.com/questions/48270127/can-a-1-a-2-a-3-ever-evaluate-to-true)
