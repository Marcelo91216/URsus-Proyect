import React, { useState } from 'react';
import './App.css';
import logo from './ursus.png';
import ResultModal from './ResultModal';

const API_BASE_URL = 'http://localhost:5000';

function App() {
  const [url, setUrl] = useState('');
  const [result, setResult] = useState(null);
  const [showModal, setShowModal] = useState(false);

  const handleSubmit = async (e) => {
    e.preventDefault();
    try {
      const response = await fetch(`${API_BASE_URL}/analyze`, {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json',
        },
        body: JSON.stringify({ url }),
      });
      if (!response.ok) {
        throw new Error('Error en la solicitud');
      }
      const data = await response.json();
      setResult(data);
    } catch (error) {
      console.error('Error:', error);
    }
  };

  const renderAnalysisInterpretation = () => {
    if (!result) return null;

    const { is_valid, last_analysis_stats } = result;

    let homographicAttackInterpretation = '';
    if (is_valid) {
      homographicAttackInterpretation = 'La URL no tiene un ataque homográfico.';
    } else {
      homographicAttackInterpretation = 'La URL tiene un ataque homográfico.';
    }

    let reputationInterpretation = '';
    if (last_analysis_stats.reputation < 0) {
      reputationInterpretation = 'La URL tiene una mala reputación dentro de la comunidad de VirusTotal.';
    } else if (last_analysis_stats.reputation === 0) {
      reputationInterpretation = 'La URL no ha sido evaluada por la comunidad de VirusTotal.';
    } else if (last_analysis_stats.reputation > 0 && last_analysis_stats.reputation < 100) {
      reputationInterpretation = 'La URL tiene una buena reputación por una pequeña parte de la comunidad.';
    } else {
      reputationInterpretation = 'La URL tiene una buena reputación en la comunidad.';
    }

    let analysisInterpretation = '';
    const { harmless, suspicious, undetected, malicious } = last_analysis_stats.analysis;
    if (harmless > suspicious + undetected + malicious) {
      analysisInterpretation = 'El análisis de VirusTotal no encontró ningún elemento sospechoso.';
    } else if (suspicious + undetected > malicious) {
      analysisInterpretation = 'El elemento posiblemente sea malicioso.';
    } else {
      analysisInterpretation = 'El elemento es malicioso.';
    }

    return (
      <div>
        <p>{homographicAttackInterpretation}</p>
        <p>{reputationInterpretation}</p>
        <p>{analysisInterpretation}</p>
      </div>
    );
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
                  {renderAnalysisInterpretation()}
                </div>
                <div className="actions">
                  <button className="desactivate" type="button" onClick={() => setShowModal(true)}>
                    Conocer más detalles
                  </button>
                </div>
              </div>
            </div>
          </div>
          {showModal && (
            <ResultModal
              result={result}
              onClose={() => setShowModal(false)}
            />
          )}
        </>
      )}
    </div>
  );
}

export default App;