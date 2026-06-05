export default function App() {
  return (
    <div className="min-h-screen bg-gradient-to-br from-blue-600 to-purple-600 flex items-center justify-center p-4">
      <div className="bg-white rounded-lg shadow-2xl p-8 max-w-md w-full text-center">
        <h1 className="text-3xl font-bold text-gray-800 mb-4">Sorting Analyzer</h1>
        <p className="text-gray-600 mb-6">A high-performance sorting algorithm comparison tool</p>
        <div className="bg-blue-50 rounded p-4 mb-6">
          <p className="text-sm text-gray-700"><strong>CLI Version:</strong> Run the C program for comprehensive analysis</p>
          <p className="text-sm text-gray-700 mt-2"><code className="bg-gray-200 px-2 py-1 rounded">cd pbl && gcc -o sorter *.c -lm && ./sorter</code></p>
        </div>
        <div className="text-left">
          <h2 className="font-bold text-gray-800 mb-2">Supported Algorithms:</h2>
          <ul className="text-sm text-gray-600 space-y-1">
            <li>✓ Bubble Sort</li>
            <li>✓ Selection Sort</li>
            <li>✓ Insertion Sort</li>
            <li>✓ Merge Sort</li>
            <li>✓ Quick Sort</li>
            <li>✓ Count Sort</li>
          </ul>
        </div>
      </div>
    </div>
  )
}
