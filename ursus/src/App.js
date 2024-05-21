import './App.css';
import logo from '/Users/alessandrotolentinohernandez/Documents/GitHub/URsus-Proyect/ursus/src/ursus.png';

import Button from 'react-bootstrap/Button';





function App() {
  return (
  <div className="App"   >
  
  <img src={logo} width = "400" />
  <br/> 

  <input placeholder="Ingresa una URL" type="text" name="text" class="input" /> 
  &nbsp;
  &nbsp;
  <button> Check </button>

  <br></br>
  <br></br>

  <h2>La URL es SUS!</h2>


  <div
       style={{
        display: "flex",
        alignItems: "center",
        justifyContent: "center",
        height: "100%"
      }}
    >

      <div class="card">
        <div class="header">
            <div class="image"><svg aria-hidden="true" stroke="currentColor" stroke-width="1.5" viewBox="0 0 24 24" fill="none">
                        <path d="M12 9v3.75m-9.303 3.376c-.866 1.5.217 3.374 1.948 3.374h14.71c1.73 0 2.813-1.874 1.948-3.374L13.949 3.378c-.866-1.5-3.032-1.5-3.898 0L2.697 16.126zM12 15.75h.007v.008H12v-.008z" stroke-linejoin="round" stroke-linecap="round"></path>
                      </svg></div>
            <div class="content">
              <span class="title">Más información sobre la URL</span>
              <p class="message">Are you sure you want to deactivate your account? All of your data will be permanently removed. This action cannot be undone.</p>
            </div>
            <div class="actions">
              <button class="desactivate" type="button">Conocer más detalles</button>
            </div>
          </div>
        </div>
  </div>
  </div>

  );
}

export default App;
