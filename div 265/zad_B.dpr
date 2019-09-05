program zad_B;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  n, i, k, j : integer;
  ar : array[1 .. 1000] of integer;
begin
  readln(n);
  for i := 1 to n do
    read(ar[i]);

  k := 0;
  i := 1;
  while(i <= n) do begin
    if(ar[i] = 1) then begin
      while (i <= n) and (ar[i] = 1) do begin
        inc(i);
        inc(k);
      end;
      for j := i to n do
        if(ar[j] = 1) then begin
          inc(k);
          break;
        end;
    end else
      inc(i);
  end;
  writeln(k);
end.
