library IEEE;
use ieee.std_logic_1164.all;

entity flip_flop_t is
    port(
        clk : in std_logic;
        t : in std_logic;
        q : out std_logic;
    );
end flip_flop_t;


architecture rtl of flip_flop_t is
begin
    process (clk)
    begin
        if rising_edge(clk) then
            if t = '1' then
                q <= d;
            end if;
        end if;
    end process;
end rtl;
