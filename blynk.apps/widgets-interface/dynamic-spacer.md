# Dynamic Spacer

{% hint style="info" %}
Available to PRO and higher plan users.
{% endhint %}

The dynamic spacer assists in the vertical positioning of widgets relative to each other, and the top/bottom of the page in the Blynk.App. The widget will help maintain consistent UI regardless of different screen sizes, making sure your important UI elements are properly positioned and never go below the screen fold.

### Widget Controls

You can [add](../constructor.md#add-widgets), [duplicate](../constructor.md#duplicate-widgets), [delete](../constructor.md#delete-a-widget), and [move](../constructor.md#move-widgets) the dynamic spacer on the canvas just like any other widget. The widget can only be [resized](../constructor.md#resize-widgets) vertically, which determines its multiplier value.

The multiplier only applies when more than one Dynamic Spacer is on the screen. The maximum multiplier value is 24x.

The Dynamic Spacer only operates on the space between it and a widget or the page top/bottom if it is sticking (edges are adjacent) to them.

### One Dynamic Spacer

Placing the Dynamic Spacer with a widget below it will cause the widget to be placed at the bottom of the page. If multiple widgets are present below the Dynamic Spacer, their relative spacing will be maintained, and the lower most widget will be aligned to the bottom page position. The multiplier setting has no effect on the spacing.

Remember, for the Dynamic Spacer to function correctly, it should be set to 'stick' to the edges of the objects above it and below. Note how the Dynamic Spacer in the example below is sticking to the top of the page, causing it to operate on the space between it and the widgets below it.

![](<../../.gitbook/assets/image (2).png>)   ![](<../../.gitbook/assets/image (6).png>)

The placement of the widget below the Dynamic Spacer to the bottom of the page is the same when the Dynamic Spacer is sticking to a widget above it (instead of the top of the page).

![](<../../.gitbook/assets/image (3).png>)   ![](<../../.gitbook/assets/image (4).png>)\
\


### Multiple Dynamic Spacers

When more than one Dynamic Spacer is on a page, then the space available to all of them is allocated in proportion to the multiplier values. In the example below, the designer has used one Dynamic Spacer with a multiplier of 5x, and another with a multiplier of 3x to locate the button widget in the space available with a ratio of 5:3 or approximately the Golden Ratio.

![](../../.gitbook/assets/image.png)   ![](<../../.gitbook/assets/image (1) (1).png>)

You have the flexibility to define any proportions you desire, and the layout will adapt seamlessly to various smartphone screen heights.

### Datastream

Dynamic Spacer is solely a UI widget and does not interact with hardware. It does not utilize any datastreams and it cannot be modified by the HTTP API.
