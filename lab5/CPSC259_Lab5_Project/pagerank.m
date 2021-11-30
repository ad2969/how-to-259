pf = 0.85;
ConnectivityMatrix = [ 0 1 0 1 0; 1 0 0 1 1; 1 0 0 1 0; 1 1 0 0 1; 1 0 0 0 0];

dimension = size(ConnectivityMatrix, 1);
columnsums = sum(ConnectivityMatrix, 1);
zerocolumns = find(columnsums ~= 0);
D = sparse(zerocolumns, zerocolumns, 1./columnsums(zerocolumns), dimension, dimension);
StochasticMatrix = ConnectivityMatrix * D;
[row, column] = find(columnsums == 0);
StochasticMatrix(:, column) = 1./dimension;
Q = ones(dimension, dimension);
TransitionMatrix = pf * StochasticMatrix + (1 - pf) * (Q/dimension);
PageRank = ones(dimension, 1);
for i = 1:100
    PageRank = TransitionMatrix * PageRank;
end
PageRank = PageRank / sum(PageRank) 