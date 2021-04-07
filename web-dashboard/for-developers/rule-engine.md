---
description: Set up specific rules with JSON
---

# Rule Engine

Example:
```
{
  "id": 1,
  "name": "Greater than (> 10F)",
  "triggers": [
    {
      "type": "MULTI_AND_TRIGGER",
      "triggers": [
        {
          "type": "PIN_TRIGGER",
          "triggerDataStream": {
            "type": "PRODUCT_DATA_STREAM",
            "productId": 1,
            "dataStreamId": 1
          }
        }
      ]
    }
  ],
  "condition": {
    "type": "GT",
    "value": 10
  },
  "actions": [
    {
      "type": "EVENT_ACTION",
      "productId": 1,
      "eventId": 18,
      "actionDelay": 0
    }
  ],
  "iterations": 0,
  "isInherited": true
}
```
