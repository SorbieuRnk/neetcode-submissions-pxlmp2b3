import numpy as np
from numpy.typing import NDArray

class Solution:

    def get_model_prediction(self, X: NDArray[np.float64], weights: NDArray[np.float64]) -> NDArray[np.float64]:
        # Compute Y_hat = X @ W (matrix multiplication)
        # X is (n, 3), weights is (3,) -> result is (n,) predictions
        # Return np.round(result, 5)
        m,n=X.shape
        y_pred=np.dot(X,weights)
        return np.round(y_pred,5)

    def get_error(self, model_prediction: NDArray[np.float64], ground_truth: NDArray[np.float64]) -> float:
        # Compute MSE = mean((predictions - truth)^2)
        # Use np.mean() and np.square()
        # Return round(result, 5)
       error=np.mean((ground_truth-model_prediction)**2)
       return np.round(error,5)
