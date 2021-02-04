---
description: >-
  This datastream accepts a fixed set of values and transforms them into desired
  outcomes.
---

# Enumerable

This Datastream specific fields INCOMING and OUTCOME allow to transform integer data to string. 

![](../../../../.gitbook/assets/enum_ds.png)

Example:  
Device has sets of three positions: Open, Vent, Closed. In means of servo they are: 130, 20 and 0   
This Datastream allows you to link these values: 130=Open, 20=Vent, 0=Closed  
So each time servo reaches any of those positions you'll get a readable state result instead of degrees.  
  
Follow these steps to create value translation:

1. click **add row**
2. set integer value than can be sent by your Device in **INCOMING** field
3. in **OUTCOME** type string value that will be used/viewed instead of original integer value
4. you can assign a color to this conversion
5. click **add row** to set further conversion values

![](../../../../.gitbook/assets/enum.gif)

