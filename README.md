# How to contribute to [Blynk 2.0 Documentation](https://github.com/blynkkk/docs)

## Documentation structure.
Keep to tree structure and mind that every entity should be described.

![struc](https://user-images.githubusercontent.com/67413917/104927828-91c74480-59aa-11eb-96af-d01e86cd2adc.PNG)

There are Sections, Directories and Articles.

While we see Directories and Articles are displayed commonly in UI we have to keep in mind that in the terms of repository structure there's a difference:

We have ``Sign Up`` and ``Restore Password`` in ``Welcome Screen`` directory.
``Sign Up`` has two articles containing so it's directory while ``Restore Password`` is an end-point and it's article.

![code-struc](https://user-images.githubusercontent.com/67413917/104929940-3b0f3a00-59ad-11eb-82fa-f25091d5f92d.PNG)

While articles contents are stored inside ``*.md`` files description to directories should be put inside README.md inside the corresponding directory.

## Article or Directory description formatting style
- When writing an article explain each object giving maximum information shortly.
- Use headers, paragraphs and lists to make it easier to read. [Example](https://github.com/blynkkk/docs/blob/main/web-dashboard/for-developers/products/dashboard/Chart.md)
- Provide the pictures in cases it can ease user's search of some specific buttons (such as ``Action``, ``Tags`` or ``Map View`` buttons) or to give explanation to separate screen sections (such as ``Main Tabs switches``, ``Devices List``, ``Device View``) 

## Link new Article or Directory to main structure
Once the Article or Directory description is written/added it should be linked inside [SUMMARY.md](https://github.com/blynkkk/docs/blob/main/SUMMARY.md) so it can be uploaded and viewed om the Web. 

To retrieve your ``*.md`` or ``directory`` path: 
- open it
- click Action button
- copy Path
![copy path](https://user-images.githubusercontent.com/67413917/104936510-4d8d7180-59b5-11eb-8a8f-83fb49878bed.PNG)

Edit SUMMARY.md by adding the relative link you got by following prevous steps to the file you've created following the [markdown](https://guides.github.com/features/mastering-markdown/) you'll see there.
