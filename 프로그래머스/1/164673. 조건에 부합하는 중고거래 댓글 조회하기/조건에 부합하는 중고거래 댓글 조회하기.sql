select 
board.title,
board.board_id,
reply.reply_id,
reply.writer_id,
reply.contents,
date_format(reply.created_date, '%Y-%m-%d') as created_date
from used_goods_board board
join used_goods_reply reply on reply.board_id = board.board_id
where board.created_date between '2022-10-01' and '2022-10-31'
order by reply.created_date asc, board.title asc

;