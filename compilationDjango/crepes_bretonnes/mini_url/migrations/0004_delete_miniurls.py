# Generated by Django 3.2 on 2020-07-06 14:45

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('mini_url', '0003_rename_miniurl_miniurls'),
    ]

    operations = [
        migrations.DeleteModel(
            name='MiniURLs',
        ),
    ]
