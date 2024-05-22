import React, { useState } from 'react';
import './App.css';
import logo from './ursus.png';

const API_BASE_URL = 'http://localhost:5000';

function App() {
  const [url, setUrl] = useState('');
  const [result, setResult] = useState(null);

  const handleSubmit = async (e) => {
    e.preventDefault();
    const response = await fetch(`${API_BASE_URL}/analyze`, {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      body: JSON.stringify({ url }),
    });
    const data = await response.json();
    setResult(data);
  };

  return (
    <div className="App">
      <img src={logo} width="400" alt="logo" />
      <br />
      <form onSubmit={handleSubmit}>
        <input
          placeholder="Ingresa una URL"
          type="text"
          name="text"
          className="input"
          value={url}
          onChange={(e) => setUrl(e.target.value)}
        />
        &nbsp;&nbsp;
        <button type="submit">Check</button>
      </form>
      <br />
      <br />
      {result && (
        <>
          <h2>La URL es {result.is_valid ? 'válida' : 'inválida'}!</h2>
          <div
            style={{
              display: 'flex',
              alignItems: 'center',
              justifyContent: 'center',
              height: '100%',
            }}
          >
            <div className="card">
              <div className="header">
                <div className="image">
                  <svg aria-hidden="true" stroke="currentColor" strokeWidth="1.5" viewBox="0 0 24 24" fill="none">
                    <path
                      d="M12 9v3.75m-9.303 3.376c-.866 1.5.217 3.374 1.948 3.374h14.71c1.73 0 2.813-1.874 1.948-3.374L13.949 3.378c-.866-1.5-3.032-1.5-3.898 0L2.697 16.126zM12 15.75h.007v.008H12v-.008z"
                      strokeLinejoin="round"
                      strokeLinecap="round"
                    ></path>
                  </svg>
                </div>
                <div className="content">
                  <span className="title">Más información sobre la URL</span>
                  <p className="message">Estadísticas del último análisis:</p>
                  <pre>{JSON.stringify(result.last_analysis_stats, null, 2)}</pre>
                </div>
                <div className="actions">
                  <button className="desactivate" type="button">
                    Conocer más detalles
                  </button>
                </div>
              </div>
            </div>
          </div>
        </>
      )}
    </div>
  );
}

export default App;