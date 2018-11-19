[@bs.module] external data : array(Js.Dict.t(string)) = "../../../../test/table/data";

let rowGetter = ({ Table.index }) => data[index];

ReactDOMRe.renderToElementWithId(
    <AutoSizer>
        (({ AutoSizer.width, height }) =>
            <Table height width rowHeight=20 headerHeight=20 rowGetter
                rowCount=Js.Array.length(data)
            >
                <Column dataKey="artist" width=0 flexGrow=1 label="Artist" />
                <Column dataKey="track" width=0 flexGrow=1 label="Track" />
            </Table>
        )
    </AutoSizer>
    ,
    "container"
);
