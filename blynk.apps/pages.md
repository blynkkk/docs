# Pages

With **Pages** you can add multiple pages to a device dashboard. They help to better organize UI and build connections between sections of your device dashboard.

![](../.gitbook/assets/image%20%2823%29.png)

#### 

### Example Of Use 

* **Device Settings.** Let's say you have a group of widgets designed for some Settings. This is not something your end-users will be using very often, so it makes sense to organize Settings widgets as a page. For end-users, this will be a tiny icon on UI which will open this page. 
* **View More Data.** Imagine you have a sensor value displayed on the dashboard and you would like to show more data, like historical data chart, explanations how to read this, show additional data points  etc. To declutter user interface, you can create a button which will open a page with all this additional information. 
* **Technical Dashboard.** Imagine you have a technical dashboard that should only be seen by users with certain role. With Pages, you can add a tab in Device Info and define which user roles can access this tab. Regular users will not see this dashboard. 



### Types Of Pages And Navigation

There are two types of pages you can add:

* Standalone pages
* Pages in Device Info View \(tabs\)

![](../.gitbook/assets/image%20%2831%29.png)

Standalone Pages can be interconnected. You can open **Page A** from **Page B** or **Page C** in any order. Just keep the navigation simple and clear for end-users.

End users open Pages by tapping on widgets which are configured to be _entry points_. They can always go back. 

Device Info Pages can only be accessed in Device Info view. 



## Standalone Pages

These pages are opened by tapping on widgets which are configured to be _entry points._ 

![](../.gitbook/assets/image%20%2830%29.png)

### 1. Creating a new page

![](../.gitbook/assets/image%20%2832%29.png)

1. Go to ToolBox → Pages → **Standalone Pages**
2. Tap **+ Add Page**
3. Give your new page a name
4. Tap **Create** in the top right corner
5. A new page is created



### 2. Editing a Page

After you created a new page, tap on it to start editing. You will see a familiar canvas with the grid where you can add widgets.

Tap on a gear icon to  access page settings, where you can Rename or Delete the page.

You can always access all of the pages and edit them in ToolBox → Pages

#### 

### 3. Linking Page to an Entry Point 

Once the page layout is ready, you need to define a page entry point. In Blynk, an entry point is a widget configured to open pages. 

#### Widgets that can be used as entry points:

* Button
* Styled Button
* Icon Button
* Image Button



To create an entry point:

![](../.gitbook/assets/image%20%2827%29.png)

1. Add one of the supported widgets to the dashboard \(check supported widgets below\)
2. Open Widget Settings
3. Set **Mode** to **Page**
4. Choose the Page to open
5. Set page appearance animation. Page can slide in from bottom or from left. 



### 4. Opening pages by end-users

After page is set up and connected to an entry point widget, it's ready for use.

1. Exit Developer Mode
2. Open the device
3. Tap on the entry point widget
4. A page should open
5. Press Back to return to the entry point



## Device Info Tabs

You can also add Pages \(in the format of Tabs\) to "More.." menu on device Dashboard. By default, this view has 2 tabs: Device Info and Timeline. They can't be deleted or removed. 

To see these tabs, end-users will need to open Device Info. This is the only entry point.

Unlike Standalone Pages, you can define which users can access the tab. For example, if you choose Admins only, users with other roles will not see this tab. This can be useful when you need to place some technical information which is only needed for administrators. 



Root User - description

### 

### 1. Adding a Tab Page

![](../.gitbook/assets/image%20%2832%29.png)

1. Go to Toolbox → Pages → **Device Info Tabs**
2. Tap **+ Add Page**
3. Give your new page a name
4. Set access permissions \(optional\)
5. Tap **Create** in the top right corner
6. A new tab page is created



### 2. Editing Tab Contents

After you created a new page, tap on it to start editing. You will see a familiar canvas with the grid where you can add widgets.

You can always access list of added tabs in Toolbox → Pages → **Device Info Tabs**



### 3. Reordering The Tabs

To change the order of tabs: 

1. Tap and hold the tab you want to move
2. Drag and drop to desired position



### 4. Deleting The Tab

In the list of Tabs swipe left to delete the tab. Keep in mind that this will delete all widgets on the tab

Optionally, you can delete the tab during editing.







