source $VIMRUNTIME/vimrc_example.vim

set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()

Plugin 'VundleVim/Vundle.vim'
Plugin 'joshdick/onedark.vim'
Plugin 'lervag/vimtex'

call vundle#end()
filetype plugin indent on

behave mswin
syntax on
colorscheme onedark

au GUIEnter * simalt ~x
autocmd GUIEnter * set vb t_vb=

"set guifont=Monaco:h200
"set guifont=Courier:h24
set backspace=indent,eol,start
"set guifont=Lucida_Console:h11:cANSI:qDRAFT
set guifont=Consolas:h15
set is
set clipboard=unnamed
"set guifont=*
set tabstop=4
set shiftwidth=4
set smartindent
set autoindent
set nocompatible
set number
set relativenumber
set nowrap
set mouse=a
set background=dark
set noerrorbells

map <F2> :%y <CR>:w <CR>
"map <F5> :w <CR>:%y <CR>
map vimrc :e! $HOME\_vimrc<CR>

"autocmd TextChanged,TextChangedI *.md silent write
function GuiTabLabel()
	let label = ''
	let bufnrlist = tabpagebuflist(v:lnum)

	for bufnr in bufnrlist
		if getbufvar(bufnr, "&modified")
			let label = '+'
			break
		endif
	endfor

	let wincount = tabpagewinnr(v:lnum, '$')
	if wincount > 1
		let label .= wincount
	endif
	if label != ''
		let label .= ' '
	endif

	return label . "%t"
endfunction
let g:vimtex_view_general_viewer = 'SumatraPDF'
            let g:vimtex_view_general_options
                \ = '-reuse-instance -forward-search @tex @line @pdf'
            let g:vimtex_view_general_options_latexmk = '-reuse-instance'
set guitablabel=%!GuiTabLabel()
" settings for sumatraPDF
" let g:vimtex_view_method = 'SumatraPDF'
" let g:vimtex_view_general_viewer = 'sumatraPDF'
" let g:vimtex_view_general_options = '-reuse-instance @pdf'
" let g:vimtex_view_general_options_latexmk = '-reuse-instance'

autocmd BufRead,BufNewFile   *.cpp inoremap { {}<Left>
autocmd BufRead,BufNewFile   *.cpp inoremap {<CR> {<CR>}<Esc>O
autocmd BufRead,BufNewFile   *.cpp inoremap {{ {
autocmd BufRead,BufNewFile   *.cpp inoremap {} {}
autocmd BufRead,BufNewFile   *.tex inoremap { {
autocmd BufRead,BufNewFile   *.tex inoremap } }
"inoremap " ""<left>
"inoremap ' ''<left>
"inoremap [ []<left>
"inoremap ( ()<left>

nnoremap <C-Tab> :tabn<CR>
nnoremap <C-w> :wq<CR>

nnoremap test :-1read C:\Users\lin\Desktop\Template\multitest.cpp <CR>:call TrimEndLines()<CR>20<CR>
nnoremap cpp :-1read C:\Users\lin\Desktop\Template\template.cpp <CR>:call TrimEndLines()<CR>23<CR>
nnoremap frac :-1read C:\Users\Home-T410\Desktop\Template\Fractions.cpp<CR>
nnoremap umap :-1read C:\Users\Home-T410\Desktop\Template\Unordered_MapHash.cpp<CR>
nnoremap mint :-1read C:\Users\Home-T410\Desktop\Template\ModInt.cpp<CR>
nnoremap factor :-1read C:\Users\Home-T410\Desktop\Template\FactorFast.cpp<CR>
nnoremap dsu :-1read C:\Users\Home-T410\Desktop\Template\DSU.cpp<CR>
nnoremap fenwick :-1read C:\Users\Home-T410\Desktop\Template\fenwick.cpp<CR>
nnoremap fenwick2d :-1read C:\Users\Home-T410\Desktop\Template\fenwick2d.cpp<CR>
nnoremap sieve :-1read C:\Users\Home-T410\Desktop\Template\Sieve.cpp<CR>
nnoremap z :-1read C:\Users\Home-T410\Desktop\Template\Z.cpp<CR>
nnoremap oset :-1read C:\Users\Home-T410\Desktop\Template\Ordered_set.cpp<CR>
nnoremap segtree :-1read C:\Users\Home-T410\Desktop\Template\segtree.cpp<CR>
nnoremap timer :-1read C:\Users\Home-T410\Desktop\Template\timer.cpp<CR>
nnoremap compress :-1read C:\Users\Home-T410\Desktop\Template\compress.cpp<CR>
nnoremap bigint :-1read C:\Users\Home-T410\Desktop\Template\BigInt.cpp<CR>
nnoremap binlift :-1read C:\Users\Home-T410\Desktop\Template\LCABinLift.cpp<CR>
nnoremap diam :-1read C:\Users\Home-T410\Desktop\Template\TreeDiameter.cpp<CR>
nnoremap mat :-1read C:\Users\Home-T410\Desktop\Template\MatExpo.cpp<CR>
nnoremap rmq :-1read C:\Users\Home-T410\Desktop\Template\RMQ.cpp<CR>
nnoremap stringhash :-1read C:\Users\Home-T410\Desktop\Template\StringHash.cpp<CR>
nnoremap rand :-1read C:\Users\Home-T410\Desktop\Template\rand.cpp<CR>
nnoremap open : :tabnew C:\Users\linli\OneDrive\Desktop\Coding\A.cpp<CR>:tabnew C:\Users\linli\OneDrive\Desktop\Coding\B.cpp<CR>:tabnew C:\Users\linli\OneDrive\Desktop\Coding\C.cpp<CR>:tabnew C:\Users\linli\OneDrive\Desktop\Coding\D.cpp<CR>:tabnew C:\Users\linli\OneDrive\Desktop\Coding\E.cpp<CR>:tabnew C:\Users\linli\OneDrive\Desktop\Coding\F.cpp<CR>:tabnew C:\Users\linli\OneDrive\Desktop\Coding\G.cpp<CR>:tabnew C:\Users\linli\OneDrive\Desktop\Coding\H.cpp<CR>:tabr<CR>:q!<CR>

"autocmd filetype cpp nnoremap <F5> :w <bar> !g++ -std=c++17 -O2 -Wall % -o %:r -Wl,--stack,268435456 && %:r.exe <CR>
autocmd filetype cpp nnoremap <F1> :w <bar> !g++ -std=c++17 % -O2 -Wuninitialized -Wparentheses -Wall -Wextra -Wno-sign-conversion -Wshadow -DLOCAL -o %:r -Wl,--stack,268435456<CR>
autocmd filetype cpp nnoremap <F2> :!%:r<CR>
autocmd filetype cpp nnoremap <C-X> :w <bar> !g++ -std=c++17 % -O2 -Wuninitialized -Wparentheses -Wall -Wextra -Wno-sign-conversion -Wshadow -DLOCAL -o %:r -Wl,--stack,268435456 && %:r.exe <CR>
autocmd filetype cpp nnoremap <C-C> :s/^\(\s*\)/\1\/\/<CR> :s/^\(\s*\)\/\/\/\//\1<CR> $$
autocmd filetype cpp nnoremap <C-A> :%s#\($\n\s*\)\+\%$##<CR>

"compilation flags for precompiling
"g++ -std=c++17 -O2 -Wuninitialized -Wparentheses -Wall -Wextra -Wno-sign-conversion -Wshadow -DLOCAL

function TrimEndLines()
	let save_cursor = getpos(".")
	silent! %s#\($\n\s*\)\+\%$##
	call setpos('.', save_cursor)
endfunction

autocmd BufWritePre *.cpp call TrimEndLines()
