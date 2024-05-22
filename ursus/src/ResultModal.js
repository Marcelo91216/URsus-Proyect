import React from 'react';
import './ResultModal.css';

const ResultModal = ({ result, onClose }) => {
    return (
        <div className="modal-overlay">
            <div className="modal-content">
                <button className="close-button" onClick={onClose}>
                    &times;
                </button>
                <h2>La URL es {result.is_valid ? 'válida, no se ha detectado un ataque homográfico' : 'inválida, esta URL es sospechosa de ser un ataque homográfico'}!</h2>
                <div className="result-container">
                    <h3>Análisis de la URL según el analizador:</h3>
                    <pre>{result.analysis}</pre>
                    <h3>Estadísticas del virustotal:</h3>
                    <div className="analysis-stats">
                        <div>
                            <strong>Inofensivos:</strong> {result.last_analysis_stats.analysis.harmless}
                        </div>
                        <div>
                            <strong>Maliciosos:</strong> {result.last_analysis_stats.analysis.malicious}
                        </div>
                        <div>
                            <strong>Sospechosos:</strong> {result.last_analysis_stats.analysis.suspicious}
                        </div>
                        <div>
                            <strong>Timeout:</strong> {result.last_analysis_stats.analysis.timeout}
                        </div>
                        <div>
                            <strong>No detectados:</strong> {result.last_analysis_stats.analysis.undetected}
                        </div>
                    </div>
                    <h3>Reputación:</h3>
                    <div>{result.last_analysis_stats.reputation}</div>
                    <h3>Votos:</h3>
                    <div className="votes">
                        <div>
                            <strong>Inofensivos:</strong> {result.last_analysis_stats.votes.harmless}
                        </div>
                        <div>
                            <strong>Maliciosos:</strong> {result.last_analysis_stats.votes.malicious}
                        </div>
                    </div>
                </div>
            </div>
        </div>
    );
};

export default ResultModal;