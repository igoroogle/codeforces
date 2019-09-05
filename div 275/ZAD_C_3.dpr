program ZAD_C_3;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  n,i,k,j,p:integer;
  a:array[1..100100] of integer;
begin
  readln(n, k);
  j := 1;
  p:=n;
  for i := 1 to k do
    if(i mod 2 = 0) then begin
      a[i]:=p;
      dec(p);
    end else begin
      a[i]:= j;
      inc(j);
    end;
  for i := k + 1 to n do begin
    if(k mod 2 = 0) then begin
      a[i] := p;
      dec(p);
    end else begin
      a[i] := j;
      inc(j);
    end;
  end;

  for i := 1 to n do
    write(a[i], ' ');
  readln;
  readln;
end.
