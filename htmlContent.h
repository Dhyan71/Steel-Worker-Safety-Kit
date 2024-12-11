const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Steel Worker Safety Kit</title>
  <style>
    body { font-family: Arial, sans-serif; text-align: center; background-color: #f4f4f9; color: #333; margin: 0; padding: 0; }
    h1 { font-size: 2.5em; color: black; margin-bottom: 20px; }
    .container { max-width: 100%; margin: auto; padding: 20px; }
    .sensor-container { display: flex; flex-wrap: wrap; justify-content: space-around; }
    .sensor-item { width: 100%; max-width: 300px; margin: 10px 0; }
    .sensor { padding: 20px; border-radius: 10px; box-shadow: 0px 4px 6px rgba(0, 0, 0, 0.1); }
    .temp-box { background-color: #FFCDD2; border: 2px solid #F44336; color: #F44336; }
    .gas-box { background-color: #C8E6C9; border: 2px solid #4CAF50; color: #4CAF50; }
    .sound-box { background-color: #BBDEFB; border: 2px solid #2196F3; color: #2196F3; }
    .alert { font-weight: bold; color: red; margin-top: 10px; font-size: 1.3em; }
    @media screen and (max-width: 768px) {
      .sensor-container { flex-direction: column; }
      .sensor-item { width: 80%; margin: 10px auto; }
    }
  </style>
</head>
<body>
  <div class="container">
    <h1>Steel Worker Safety Kit</h1>
    <div class="sensor-container">
      <div class="sensor-item">
        <div class="sensor temp-box">
          <h2>Temperature</h2>
          <p id="temp">--</p><p class="unit">°C</p>
          <p class="alert" id="tempAlert"></p>
        </div>
      </div>
      <div class="sensor-item">
        <div class="sensor gas-box">
          <h2>Gas Level</h2>
          <p id="gas">--</p><p class="unit">PPM</p>
          <p class="alert" id="gasAlert"></p>
        </div>
      </div>
      <div class="sensor-item">
        <div class="sensor sound-box">
          <h2>Sound Level</h2>
          <p id="sound">--</p><p class="unit">Hz</p>
          <p class="alert" id="soundAlert"></p>
        </div>
      </div>
    </div>
  </div>
  <script>
    setInterval(() => {
      fetch('/data').then(response => response.json()).then(data => {
        document.getElementById('temp').innerText = data.temperature.toFixed(2);
        document.getElementById('gas').innerText = data.gas;
        document.getElementById('sound').innerText = data.sound;
        document.getElementById('tempAlert').innerText = data.tempAlert ? "Heat Hazard!" : "";
        document.getElementById('gasAlert').innerText = data.gasAlert ? "Gas Hazard!" : "";
        document.getElementById('soundAlert').innerText = data.soundAlert ? "Sound Hazard!" : "";
      });
    }, 1000);
  </script>
</body>
</html>
)rawliteral";
