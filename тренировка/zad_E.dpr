program zad_E;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  i, j, x, y,  q :integer;
  s :string;
begin


    readln(s);
    q := 1;
    while (q <> 0) do
    begin
        q := 0;

        for i := 1 to length(s) -  1 do
        if (s[i] <> s[i + 1]) then
        begin
            delete(s, i, 2);
            inc(q);
            break;

        end;
        if (q = 0) then
            break;
    end;

    if (s = '') then
        writeln('YES')
   else
       writeln('NO');     
    readln;
    readln;
end.
