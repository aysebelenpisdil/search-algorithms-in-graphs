# BFS Pseudo Code

```

BFS(G, s)
 for each u in V - {s}
  color[u] = white
  d[u] = ∞
  pi[u] = null
 endfor
 color[s] = gray
 d[s] = 0
 pi[s] = null
 ENQUEUE(Q, s)
 while Q ≠ empty
  u = DEQUEUE(Q)
  for each v in Adj[u]
   if color[v] = white
    color[v] = gray
    d[v] = d[u] + 1
    pi[v] = u
    ENQUEUE(Q, v)
   endif
  endfor
  color[u] = black
 endwhile
endBFS

```

# DFS Pseudo Code

```
DFS(G)
 for each u in V
  color[u] = white
  pi[u] = null
 endfor
 time = 0
 for each u in V
  if color[u] = white
   DFSVisit(u)
  endif
 endfor
endDFS

DFSVisit(u)
 time = time + 1
 d[u] = time
 color[u] = gray
 for each v in Adj[u]
  if color[v] = white
   pi[v] = u
   DFSVisit(v)
  endif
 endfor
 color[u] = black
 time = time + 1
 f[u] = time
endDFSVisit

```
