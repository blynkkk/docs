# Pages

With **Pages** you can add multiple pages to a device dashboard. This helps to better organize the UI and build connections between sections of your device dashboard.

![](<../.gitbook/assets/image (23).png>)

####

### Examples Of Use 

* **Device Settings.** Let's say you plan to use a group of widgets for various Settings. This is not something your end-users will be using very often, so it makes sense to organize Settings widgets as into a separate page. For end-users, there will be a tiny icon in the UI which will open this page. 
* **View More Data.** Imagine you have a sensor value displayed on the dashboard and you would like to show more data, like historical data chart, explanations how to read this, show additional data points  etc. To de-clutter the user interface, you can create a button which will open a page with all of this additional information. 
* **Technical Dashboard.** Imagine you have a technical dashboard that should only be seen by users with a certain role. With Pages, you can add a tab in Device Info and define which user roles can access this tab. Users with other roles will not see this dashboard. 

{% hint style="warning" %}
Pages feature is available in paid plans only. You can always upgrade in your Account Settings.
{% endhint %}

### Types Of Pages And Navigation

There are two types of pages you can add:

* Standalone pages
* Pages in Device Info View (tabs)

![](<../.gitbook/assets/image (31).png>)

Standalone Pages can be interconnected. You can open **Page A** from **Page B** or **Page C** in any order. Just keep the navigation simple and clear for end-users.

End users open Pages by tapping on widgets which are set as _entry points_. Users can always go back to the previous view. 

Device Info Pages can only be accessed in Device Info view. 



## Standalone Pages

These pages are opened by tapping on widgets that are set as _entry points. _

![](<../.gitbook/assets/image (30).png>)

### 1. Creating a new page

![](<../.gitbook/assets/image (32).png>)

1. Go to ToolBox → Pages → **Standalone Pages**
2. Tap **+ Add Page**
3. Give your new page a name
4. Tap **Create **in the top right corner
5. Your new page is created



### 2. Editing a Page

After you have created a new page, tap on it to start editing. You will see a familiar canvas with the grid where you can add widgets.

Tap on the gear icon to  access page settings, where you can Rename or Delete the page.

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

![](<../.gitbook/assets/image (27).png>)

1. Add one of the supported widgets to the dashboard (check supported widgets below)
2. Open Widget Settings
3. Set **Mode** to **Page**
4. Choose the Page to open
5. Set page appearance animation (how the page appears on screen). The page can slide in from the bottom or from the left. 



### 4. Opening pages by end-users

After the page has been set up and connected to an entry point widget, it's ready for use.

1. Exit Developer Mode
2. Open the device
3. Tap on the entry point widget
4. A page should open
5. Press Back to return to the entry point



## Device Info Tabs

You can also add Pages (in the format of Tabs) to "More.." menu on device Dashboard. By default, this view has 2 tabs: Device Info and Timeline. They can't be deleted or removed. 

To see these tabs, end-users will need to open Device Info. This is the only entry point.

Unlike Standalone Pages, you can define which users can access the tab. For example, if you choose Admins only, users with other roles will not see this tab. This can be useful when you need to place some technical information which is only needed for administrators. 



Root User - description

###

### 1. Adding a Tab Page

![](<../.gitbook/assets/image (32).png>)

1. Go to Toolbox → Pages → **Device Info Tabs**
2. Tap **+ Add Page**
3. Give your new page a name
4. Set access permissions (optional)
5. Tap **Create **in the top right corner
6. A new tab page is created



### 2. Editing Tab Contents

After you have created a new page, tap on it to start editing. You will see a familiar canvas with the grid where you can add widgets.

You can always access list of added tabs in Toolbox → Pages → **Device Info Tabs**



### 3. Reordering The Tabs

To change the order of tabs: 

1. Tap and hold the tab you want to move
2. Drag and drop to desired position



### 4. Deleting The Tab

To delete the tab, swipe left in the list of Tabs . Keep in mind that this will delete all widgets on the tab.

Alternatively, you can delete the tab during editing.





