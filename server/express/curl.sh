curl -s -X POST http://localhost:3000 -H "Content-Type: application/json" -d '{"query":"{hello}"}' | jq .
