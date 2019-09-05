program zzzz14;

{$APPTYPE CONSOLE}

uses
  SysUtils,Windows;

var
    cd,name:array[1..300] of string;
    n, i, j,k: integer;
    tmp, tmp2, tmp1: string;
    ans: array[1..300, 1..300] of string;
    free: array[0..300] of integer;
    f: text;
    l, r: integer;
    flg: boolean;
procedure add(s1, s2: string);
var
    i, j, k: integer;
begin
    for i := 1 to free[0] do
        for j := 1 to free[i] do
            if (ans[i, j] = s1) or (ans[i, j] = s2) then
            begin
                if (ans[i, j] = s1) then
                begin
                    for k := 1 to free[i] do
                        if (ans[i, k] = s2) then
                            exit;
                    inc(free[i]);
                    ans[i, free[i]] := s2
                end
                else
                begin
                    for k := 1 to free[i] do
                        if (ans[i, k] = s1) then
                            exit;
                    inc(free[i]);
                    ans[i, free[i]] := s1;
                end;
                exit;
            end;

    inc(free[0]);
    free[free[0]] := 2;
    ans[free[0], 1] := s1;
    ans[free[0], 2] := s2;
end;

function get(s: string): string;
begin
    result := '';
    if (pos('.', s) > 0) then
        result := copy(s, pos('.', s) + 1, length(s) - pos('.', s));
    if (length(result) >= 2) and (copy(result, 1, 2) = 'py') then
        result := 'py';
    if (result = 'pm') or (result = 'cgi') then
        result := 'pl';
    if (result = 'rb') or (result = 'rbw') then
        result := 'rb';
end;

procedure format(name1: string; var code1: string);
var
    tmp: string;
    j1, f: integer;
begin
    code1 := lowercase(code1);

    if (get(name1) = 'c') or
       (get(name1) = 'cpp') or
       (get(name1) = 'java') or
       (get(name1) = 'cs') or
       (get(name1) = 'd') then
    begin
        while (pos('/*', code1) > 0) and (pos('/*', code1) < pos('*/', code1)) do
        begin
            f := pos('/*', code1);
            delete(code1, f, pos('*/', code1)-f+1);
        end;
    end;

    if (get(name1) = 'pas') or (get(name1) = 'dpr') then
    begin
        while (pos('{', code1) > 0) and (pos('{', code1) < pos('}', code1)) do
        begin
            f := pos('{', code1);
            delete(code1, f, pos('}', code1)-f);
        end;
    end;
    tmp := '';
    for j1 := 1 to length(code1) do
            if (code1[j1] in ['a'..'z']) or (code1[j1] = ',') or (code1[j1] = '.')
            or (code1[j1] = ';') or (code1[j1] = ':') then continue
            else
            begin
                if code1[j1] in ['0'..'9'] then continue;
                    if (code1[j1] in [#34..#34]) or
                    (code1[j1] in [#35..#39]) or
                    (code1[j1] in [#40..#57]) or
                    (code1[j1] in [#59..#59]) or
                    (code1[j1] in [#61..#61]) or
                    (code1[j1] in [#91..#91]) or
                    (code1[j1] in [#93..#95]) or
                    (code1[j1] in [#123..#125])
                    then tmp := tmp + code1[j1];
            end;
    code1 := tmp;
end;

function check(n1, n2: integer):boolean;
var
   k1, k2, j:integer;
   s1, s2: string;
begin
    s1 := cd[n1];
    s2 := cd[n2];
    k1 := 0;
    k2 := k1;
     for j := 1 to length(s1)-15+1 do
        if pos(copy(s1, j, 15), s2) <> 0 then inc(k1)
        else inc(k2);
    s1 := cd[n2];
    s2 := cd[n1];
    for j := 1 to length(s1)-15+1 do
        if pos(copy(s1, j, 15), s2) <> 0 then inc(k1)
        else inc(k2);
    if (k1 > k2 * 60 / 100) then result := true
    else result := false;
end;

begin
    assign(input, 'input.txt');
    assign(output, 'output.txt');
    reset(input);
    rewrite(output);
    readln(n);
    for i := 1 to n do
    begin
        readln(name[i]);
        assign(f, name[i]);
        reset(f);
        while (not eof(f)) do
        begin
            if tmp1 = '' then
            readln(f, tmp)
            else
            begin
                tmp := '';
                tmp1 := '';
            end;
            tmp := lowercase(tmp);
            l := 0;
            r := 0;
            for j := 1 to length(tmp) do
            begin
                if tmp[j] = '(' then inc(l);
                if tmp[j] = ')' then inc(r);
                if (tmp[j] = ';') and (l = r) then
                begin
                    k := j;
                    tmp1 := copy(tmp, k+1, length(tmp)-k+2);
                    tmp := copy(tmp, 1, k);
                    break;
                end;
            end;
            for j := length(tmp) downto 1 do
                if (tmp[j] = ' ') then delete(tmp, j, 1);

            if (pos('//', tmp) > 0) then
                delete(tmp, pos('//', tmp), length(tmp) - pos('//', tmp) + 1);
            if (pos('#', tmp) > 0) and
               (get(name[i]) = 'py') or
               (get(name[i]) = 'pl') or
               (get(name[i]) = 'rb') or
               (get(name[i]) = 'd') then
                delete(tmp, pos('#', tmp), length(tmp) - pos('#', tmp));

            if (get(name[i]) = 'pas') or
               (get(name[i]) = 'dpr') or
               (get(name[i]) = 'c') or
               (get(name[i]) = 'cpp') or
               (get(name[i]) = 'java') or
               (get(name[i]) = 'py') or
               (get(name[i]) = 'pl') or
               (get(name[i]) = 'rb') or
               (get(name[i]) = 'd') then
            begin
                tmp2 := '';
                flg := true;
                for j := 1 to length(tmp) do
                begin
                    if (tmp[j] = '''') or
                       (tmp[j] = '"') then
                        flg := not flg;
                    if (flg) then
                        tmp2 := tmp2 + tmp[j];
                end;
                tmp := tmp2;
                for j := length(tmp) downto 1 do
                    if (tmp[j] = ' ') then delete(tmp, j, 1);
            end;

            cd[i] := cd[i] + ' ' + tmp;
        end;
        format(name[i], cd[i]);
        close(f);
    end;
    free[0] := 0;
    for i := 1 to n do
        for j := i + 1 to n do
        begin
            if (check(i, j)) then
                add(name[i], name[j]);
        end;

    writeln(free[0]);
    for i:=1 to free[0] do
    begin
        for j:=1 to free[i] do
            write(ans[i,j], ' ');
        writeln;
    end;

    close(input);
    close(output);
end.
