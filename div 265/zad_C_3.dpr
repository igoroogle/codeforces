program zad_C;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  st, st2 : string;
  n, i, j, p, k: integer;
begin
  readln(n, p);
  readln(st);

  st := '0`' + st;
  st2 := st;

  n := n + 2;
  for i := n downto 3 do begin
    while(st2[i] < chr(96 + p)) do begin
      inc(st2[i]);
      if(st2[i] <> st2[i - 1]) and (st2[i] <> st2[i - 2]) then begin
        k := i;
        if(st2[i - 1] = 'a') then begin
          st2[i + 1] := 'b';
          inc(k);
        end;

        for j := 1 to n - k do
          if(j mod 3 = 1) then
            st2[j + k] := 'a'
          else if (j mod 3 = 2) then
            st2[j + k] := 'b'
          else
            st2[j + k] := 'c';
         writeln(copy(st2, 3, n));

         readln(n);
         exit;
      end;
    end;
    st2[i] := st[i];
  end;

  writeln('NO');
end.
