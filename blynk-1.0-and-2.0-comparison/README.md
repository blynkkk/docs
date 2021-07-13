# Changes from Blynk 0.1

<table>
  <thead>
    <tr>
      <th style="text-align:left">Feature</th>
      <th style="text-align:left">Difference</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td style="text-align:left"><b>Apps</b>
      </td>
      <td style="text-align:left"></td>
    </tr>
    <tr>
      <td style="text-align:left">Web Dashboard</td>
      <td style="text-align:left">&#x1F389; New <b>Blynk.Console</b>
      </td>
    </tr>
    <tr>
      <td style="text-align:left">Android App</td>
      <td style="text-align:left">
        <p>Legacy Blynk requires <b>Android 4.2</b> or later</p>
        <p>Blynk IoT requires <b>Android 5</b> or later</p>
      </td>
    </tr>
    <tr>
      <td style="text-align:left">iOS App</td>
      <td style="text-align:left">
        <p>Legacy Blynk requires <b>iOS 9</b> or later</p>
        <p>Blynk IoT requires <b>iOS 14.1</b> or later</p>
      </td>
    </tr>
    <tr>
      <td style="text-align:left"><b>Device Management</b>
      </td>
      <td style="text-align:left"></td>
    </tr>
    <tr>
      <td style="text-align:left">Voice Assistants</td>
      <td style="text-align:left">&#x1F389; <b>Alexa</b> and <b>Google Home</b> integration (coming soon)</td>
    </tr>
    <tr>
      <td style="text-align:left">Device Provisioning and Profiling</td>
      <td style="text-align:left">&#x1F389; New in <b>Blynk.Edgent</b> and <b>Blynk.Apps</b>
      </td>
    </tr>
    <tr>
      <td style="text-align:left">Over-the-Air firmware updates (Blynk.Air)</td>
      <td style="text-align:left">&#x1F389; New in <b>Blynk.Edgent</b> and <b>Blynk.Console</b>
      </td>
    </tr>
    <tr>
      <td style="text-align:left">Event Logging</td>
      <td style="text-align:left">&#x1F389; New in <b>Blynk.Console</b> and <b>Blynk.Apps</b>
      </td>
    </tr>
    <tr>
      <td style="text-align:left">Notifications management</td>
      <td style="text-align:left">&#x1F389; New in <b>Blynk.Console</b>
      </td>
    </tr>
    <tr>
      <td style="text-align:left">Device and User Management</td>
      <td style="text-align:left">&#x1F389; New in <b>Blynk.Console</b>
      </td>
    </tr>
    <tr>
      <td style="text-align:left">User Roles and Permissions</td>
      <td style="text-align:left">&#x1F389; New in <b>Blynk.Console</b>
      </td>
    </tr>
    <tr>
      <td style="text-align:left"><a href="https://docs.blynk.io/en/blynk.console/devices/device-sharing">Device Sharing</a> (via
        QR code)</td>
      <td style="text-align:left">&#x2705; Replaced by inviting users</td>
    </tr>
    <tr>
      <td style="text-align:left"><b>Connectivity</b>
      </td>
      <td style="text-align:left"></td>
    </tr>
    <tr>
      <td style="text-align:left">Bluetooth 2.0 SPP</td>
      <td style="text-align:left">&#x274C; Not available in new Blynk (yet)</td>
    </tr>
    <tr>
      <td style="text-align:left">Bluetooth Low Energy (BLE)</td>
      <td style="text-align:left">&#x274C; Not available in new Blynk (yet)</td>
    </tr>
    <tr>
      <td style="text-align:left"><b>Widgets</b>
      </td>
      <td style="text-align:left"></td>
    </tr>
    <tr>
      <td style="text-align:left">Bridge widget</td>
      <td style="text-align:left">&#x2705; Replaced by <b>Automations</b> and <b>Rule Engine</b> (coming soon)</td>
    </tr>
    <tr>
      <td style="text-align:left">Eventor widget</td>
      <td style="text-align:left">&#x2705; Replaced by <b>Automations.</b> Now works on iOS and Android</td>
    </tr>
    <tr>
      <td style="text-align:left">Timer widget</td>
      <td style="text-align:left">&#x2705; Replaced by <b>Automations</b>
      </td>
    </tr>
    <tr>
      <td style="text-align:left">RTC widget</td>
      <td style="text-align:left">&#x2705; No widget needed. Use <a href="../blynk.edgent/api/rtc-clock.md">Time API</a>
      </td>
    </tr>
    <tr>
      <td style="text-align:left">WebHook widget</td>
      <td style="text-align:left">&#x2705; Replaced by WebHook settings in <b>Blynk.Console</b>
      </td>
    </tr>
    <tr>
      <td style="text-align:left">Notifications, Email, Twitter widgets</td>
      <td style="text-align:left">&#x2705; Replaced by Template Events</td>
    </tr>
    <tr>
      <td style="text-align:left">Terminal widget</td>
      <td style="text-align:left">Works only in realtime. History not supported</td>
    </tr>
    <tr>
      <td style="text-align:left">Table widget</td>
      <td style="text-align:left">&#x274C; Not available in new Blynk (yet)</td>
    </tr>
    <tr>
      <td style="text-align:left">Device Selector</td>
      <td style="text-align:left">&#x274C; Replaced with Device Tiles</td>
    </tr>
    <tr>
      <td style="text-align:left">Multi-device projects</td>
      <td style="text-align:left">&#x274C; Replaced with Device Tiles and <b>Dashboards</b> (coming soon)</td>
    </tr>
    <tr>
      <td style="text-align:left">Reports</td>
      <td style="text-align:left">&#x2705; Moved to <b>Blynk.Console<br /></b>Scheduled reports not yet available</td>
    </tr>
    <tr>
      <td style="text-align:left">Widget min/max set property</td>
      <td style="text-align:left">&#x274C; Widget min/max fields were moved to datastream settings</td>
    </tr>
    <tr>
      <td style="text-align:left"><b>Cloud</b>
      </td>
      <td style="text-align:left"></td>
    </tr>
    <tr>
      <td style="text-align:left">Local Server</td>
      <td style="text-align:left">&#x274C; Available in <b>White-label</b> plan only</td>
    </tr>
    <tr>
      <td style="text-align:left">Private Business Server</td>
      <td style="text-align:left">&#x2705; Remains available for White-label clients</td>
    </tr>
    <tr>
      <td style="text-align:left"><b>Pricing Model</b>
      </td>
      <td style="text-align:left"></td>
    </tr>
    <tr>
      <td style="text-align:left">Blynk Energy</td>
      <td style="text-align:left">Replaced with <a href="https://blynk.io/pricing#!/tab/318474072-1">subscription plans</a>
      </td>
    </tr>
  </tbody>
</table>

