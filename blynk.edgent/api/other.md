
## Minimizing footprint

To minimize the program Flash/RAM, you can disable some of the built-in functionality:

1. Comment-out `#define BLYNK_PRINT` to remove prints
2. Put on the top of your sketch:

   ```text
   #define BLYNK_NO_BUILTIN   // Disable built-in analog & digital pin operations
   #define BLYNK_NO_FLOAT     // Disable float operations
   ```

## Porting, hacking

If you want to dive into crafting/hacking/porting Blynk library implementation, please also check [this documentation](https://github.com/blynkkk/blynk-library/tree/master/extras/docs).
