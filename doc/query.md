# Query Class

Query is a class for usage with [Client #query](client.md#query) methods.
Queries need indexes on queried bins.

Aerospike reference: http://www.aerospike.com/docs/guide/query.html

```ruby
q_range = AerospikeC::Query.new("test", "query_test")
q_range.range!("int_bin", 5, 10)
```

With a new operation, you can use any of the methods specified below:

- [Methods](#methods)
  - [#initialize](#initialize)
  - [#eql!](#eql!)
  - [#range!](#range!)
  - [#geo_contains!](#geo_contains!)
  - [#geo_within!](#geo_within!)
  - [#order_by!](#order_by!)
  - [#namespace](#namespace)
  - [#set](#set)
  - [#bins](#bins)
  - [#policy=](#policy=)

<a name="methods"></a>
## Methods

<!--===============================================================================-->
<!-- initialize -->
<a name="initialize"></a>

### initialize(namespace, set, bins = [])

Parameters:

- `namespace` - namespace to perform query on
- `set`       - set to perform query on
- `bins`      - bins to get from queried records (default mean all)

Example:

```ruby
q1 = AerospikeC::Query.new("test", "query_test")
q2 = AerospikeC::Query.new("test", "query_test", ["string_bin", "other_bin"])
```

<!--===============================================================================-->
<hr/>
<!-- eql! -->
<a name="eql!"></a>

### eql!(bin, value)

Parameters:

- `bin`   - bin name to check equality
- `value` - value of bin

Retrun `self`

Example:

```ruby
q_eql = AerospikeC::Query.new("test", "query_test", ["string_bin", "other_bin"])
q_eql.eql!("string_bin", "string21")
```

<!--===============================================================================-->
<hr/>
<!-- range! -->
<a name="range!"></a>

### range!(bin, min, max)

Parameters:

- `bin` - bin to check range
- `min` - minimum value of bin
- `max` - maximum value of bin

Retrun `self`

Example:

```ruby
q_range = AerospikeC::Query.new("test", "query_test")
q_range.range!("int_bin", 5, 10)
```


<!--===============================================================================-->
<hr/>
<!-- geo_contains! -->
<a name="geo_contains!"></a>

### geo_contains!(bin, geo)

Parameters:

- `bin` - bin with geo index
- `geo` - [AerospikeC::GeoJson](geo_json.md) object

Retrun `self`

Example:

```ruby
point = AerospikeC::GeoJson.point(1, 5)
q_geo = AerospikeC::Query.new("test", "geo_json")
q_geo.geo_contains!("geo_bin", point)
```

<!--===============================================================================-->
<hr/>
<!-- geo_within! -->
<a name="geo_within!"></a>

### geo_within!(bin, geo)

Parameters:

- `bin` - bin with geo index
- `geo` - [AerospikeC::GeoJson](geo_json.md) object

Retrun `self`

Example:

```ruby
circle = AerospikeC::GeoJson.circle([0, 0], 100 * 1000)
q_geo = AerospikeC::Query.new("test", "geo_json")
q_geo.geo_within!("geo_bin", circle)
```


<!--===============================================================================-->
<hr/>
<!-- order_by! -->
<a name="order_by!"></a>

### order_by!(bin, type)

Parameters:

- `bin` - bin to order by
- `type` - symbol, order type, `:asc` or `:desc`

Retrun `self`


<!--===============================================================================-->
<hr/>
<!-- namespace -->
<a name="namespace"></a>

### namespace

Retruns instance `namespace`

<!--===============================================================================-->
<hr/>
<!-- set -->
<a name="set"></a>

### set

Retruns instance `set`

<!--===============================================================================-->
<hr/>
<!-- bins -->
<a name="bins"></a>

### bins

Retruns instance `bins`


<!--===============================================================================-->
<hr/>
<!-- policy= -->
<a name="policy="></a>

### policy=(policy)

Parameters:

- `policy` - [AerospikeC::QueryPolicy](policy.md#query_policy) object