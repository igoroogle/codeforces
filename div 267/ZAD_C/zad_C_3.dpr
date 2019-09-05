program zad_C;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  n,m,k,i,j:integer;
  max:int64;
  a:array[1..5100] of int64;
  s,s1 : array[0 .. 5100] of int64;
  dp : array[0 .. 5100, 0 .. 5100] of int64;
begin
  readln(n, m, k);
  for i := 1 to n do
    read(a[i]);

  s1[0] := 0;
  s1[1] := a[1];
  for i := 2 to n do
    s1[i] := s1[i - 1] + a[i];

  for i := m to n do
    s[i] := s1[i] - s1[i - m];

  max := 0;
  for j := m to n do begin
    if(j > m) and (dp[1, j - 1] > s[j]) then
      dp[1, j] := dp[1, j - 1]
    else
      dp[1, j] := s[j];
    if(max < dp[1, j]) then
        max := dp[1, j];
    for i := 2 to k do begin
      dp[i, j] := dp[i, j - 1];
      if(j div m < i) then
        dp[i, j] := 0
      else if (dp[i, j] < dp[i - 1, j - m] + s[j]) then
        dp[i, j] := dp[i - 1, j - m] + s[j];
      if(max < dp[i, j]) then
        max := dp[i, j];
    end;
  end;
  writeln(max);
  readln;
end.
